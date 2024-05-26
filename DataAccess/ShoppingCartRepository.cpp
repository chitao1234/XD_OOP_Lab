//
// Created by chi on 24/05/05.
//

#include <stdexcept>
#include <utility>
#include "ShoppingCartRepository.h"
#include "ShoppingCartDao.h"

namespace DataAccess {
    using DataType::Product;

    std::vector<std::pair<Product, long>> ShoppingCartRepository::listProducts() {
        std::vector<std::pair<Product, long>> products;
        for (auto &productId: shoppingCartDao->listProductIds(username)) {
            products.emplace_back(productRepository.getProduct(productId.first).value(), productId.second);
        }
        return products;
    }

    ShoppingCartRepository::ShoppingCartRepository(IDaoFactory &daoFactory,
                                                   IProductRepository &productRepository,
                                                   std::string username)
            : username(std::move(username)),
              productRepository(productRepository),
              shoppingCartDao(daoFactory.getShoppingCartDao()),
              orderDao(daoFactory.getOrderDao()),
              productOrderDao(daoFactory.getProductOrderDao()) {}

    ShoppingCartRepository::~ShoppingCartRepository() {
        delete shoppingCartDao;
        delete orderDao;
        delete productOrderDao;
    }

    void ShoppingCartRepository::addProduct(uint64_t productId, long quantity) {
        long originalQuantity = shoppingCartDao->getProductQuantity(username, productId);
        if (originalQuantity < 0) originalQuantity = 0;
        shoppingCartDao->updateProductQuantity(username, productId, originalQuantity + quantity);
        shoppingCartDao->save();
    }

    void ShoppingCartRepository::removeProduct(uint64_t productId) {
        shoppingCartDao->removeProduct(username, productId);
        shoppingCartDao->save();
    }

    void ShoppingCartRepository::updateProductQuantity(uint64_t productId, long quantity) {
        if (quantity <= 0) {
            shoppingCartDao->removeProduct(username, productId);
        } else {
            shoppingCartDao->updateProductQuantity(username, productId, quantity);
        }
        shoppingCartDao->save();
    }

    void ShoppingCartRepository::clearCart() {
        shoppingCartDao->clearCart(username);
        shoppingCartDao->save();
    }

    bool ShoppingCartRepository::exportToFile(std::string filename) {
        return shoppingCartDao->exportToFile(username, std::move(filename));
    }

    bool ShoppingCartRepository::importFromFile(std::string filename) {
        return shoppingCartDao->importFromFile(username, std::move(filename));
    }

    void ShoppingCartRepository::addOrder(std::vector<std::pair<DataType::Product, long>> products, double price) {
        DataType::Order order = {orderDao->nextId(),
                                 username,
                                 price,
                                 std::chrono::system_clock::now()
        };

        orderDao->addOrder(order);
        for (auto &product: products) {
            productOrderDao->addProductToOrder(order.getPurchaseId(),
                                               product.first.getId(),
                                               product.second);
        }
    }

    DataType::FullOrder ShoppingCartRepository::getFullOrder(uint64_t orderId) {
        DataType::Order order = orderDao->getOrder(orderId);
        std::vector<std::pair<Product, long>> products;
        for (auto &product: productOrderDao->getProducts(orderId)) {
            products.emplace_back(productRepository.getProduct(product.first).value(), product.second);
        }
        return {order, products};
    }

    std::vector<DataType::FullOrder> ShoppingCartRepository::filterOrders(
            std::optional<std::string> keyword,
            std::optional<std::chrono::system_clock::time_point> start,
            std::optional<std::chrono::system_clock::time_point> end) {
        auto orders = orderDao->filterOrders(username);
        std::vector<DataType::FullOrder> result;
        for (auto &order: orders) {
            DataType::FullOrder fullOrder = getFullOrder(order.getPurchaseId());

            if (keyword.has_value()) {
                for (auto &product: fullOrder.getProducts()) {
                    if (product.first.getName().find(keyword.value()) == std::string::npos) {
                        continue;
                    }
                }
            }

            if (start.has_value() && order.getPurchaseTime() < start.value()) {
                continue;
            }

            if (end.has_value() && order.getPurchaseTime() > end.value()) {
                continue;
            }

            result.push_back(std::move(fullOrder));
        }
        return result;
    }

}
