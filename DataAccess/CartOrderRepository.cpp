//
// Created by chi on 24/05/05.
//

#include <stdexcept>
#include <utility>
#include "CartOrderRepository.h"
#include "ShoppingCartDao.h"
#include "DataType/FullProduct.h"

namespace DataAccess {
    std::vector<std::pair<DataType::FullProduct, long>> CartOrderRepository::listProducts() {
        std::vector<std::pair<DataType::FullProduct, long>> products;
        for (auto &productId: shoppingCartDao->listProductIds(username)) {
            products.emplace_back(productRepository.getProduct(productId.first).value(), productId.second);
        }
        return products;
    }

    CartOrderRepository::CartOrderRepository(IDaoFactory &daoFactory,
                                             IProductRepository &productRepository,
                                             std::string username)
            : username(std::move(username)),
              productRepository(productRepository),
              shoppingCartDao(daoFactory.getShoppingCartDao()),
              orderDao(daoFactory.getOrderDao()),
              productOrderDao(daoFactory.getProductOrderDao()) {}

    CartOrderRepository::~CartOrderRepository() {
        delete shoppingCartDao;
        delete orderDao;
        delete productOrderDao;
    }

    void CartOrderRepository::addProduct(uint64_t productId, long quantity) {
        long originalQuantity = shoppingCartDao->getProductQuantity(username, productId);
        if (originalQuantity < 0) originalQuantity = 0;
        shoppingCartDao->updateProductQuantity(username, productId, originalQuantity + quantity);
        shoppingCartDao->save();
    }

    void CartOrderRepository::removeProduct(uint64_t productId) {
        shoppingCartDao->removeProduct(username, productId);
        shoppingCartDao->save();
    }

    void CartOrderRepository::updateProductQuantity(uint64_t productId, long quantity) {
        if (quantity <= 0) {
            shoppingCartDao->removeProduct(username, productId);
        } else {
            shoppingCartDao->updateProductQuantity(username, productId, quantity);
        }
        shoppingCartDao->save();
    }

    void CartOrderRepository::clearCart() {
        shoppingCartDao->clearCart(username);
        shoppingCartDao->save();
    }

    bool CartOrderRepository::exportToFile(std::string filename) {
        return shoppingCartDao->exportToFile(username, std::move(filename));
    }

    bool CartOrderRepository::importFromFile(std::string filename) {
        return shoppingCartDao->importFromFile(username, std::move(filename));
    }

    void CartOrderRepository::addOrder(std::vector<std::pair<DataType::FullProduct, long>> products, double price) {
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
        orderDao->save();
        productOrderDao->save();
    }

    DataType::FullOrder CartOrderRepository::getFullOrder(const DataType::Order& order) {
        std::vector<std::pair<DataType::FullProduct, long>> products;
        for (auto &product: productOrderDao->getProducts(order.getPurchaseId())) {
            products.emplace_back(productRepository.getProduct(product.first).value(), product.second);
        }
        return {order, products};
    }

    std::vector<DataType::FullOrder> CartOrderRepository::filterOrders(
            std::optional<std::string> keyword,
            std::optional<std::chrono::system_clock::time_point> start,
            std::optional<std::chrono::system_clock::time_point> end) {
        auto orders = orderDao->filterOrders(username);
        std::vector<DataType::FullOrder> result;
        for (auto &order: orders) {
            DataType::FullOrder fullOrder = getFullOrder(order);

            if (keyword.has_value()) {
                bool found = false;
                for (auto &product: fullOrder.getProducts()) {
                    if (product.first.getName().find(keyword.value()) != std::string::npos) {
                        found = true;
                        break;
                    }
                }
                // reach here means no product in the order contains the keyword
                if (!found) {
                    continue;
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
