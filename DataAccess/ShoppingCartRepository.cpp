//
// Created by chi on 24/05/05.
//

#include <stdexcept>
#include <utility>
#include "ShoppingCartRepository.h"
#include "ShoppingCartDao.h"

namespace DataAccess {
    using DataType::Product;

    std::vector <std::pair<Product, long>> ShoppingCartRepository::listProducts() {
        std::vector <std::pair<Product, long>> products;
        for (auto &productId: shoppingCartDao->listProductIds(username)) {
            products.emplace_back(productRepository.getProduct(productId.first).value(), productId.second);
        }
        return products;
    }

    ShoppingCartRepository::ShoppingCartRepository(IDaoFactory &daoFactory, IProductRepository &productRepository, std::string username)
            : username(std::move(username)), productRepository(productRepository),
              shoppingCartDao(daoFactory.getShoppingCartDao()) {
    }

    ShoppingCartRepository::~ShoppingCartRepository() {
        delete shoppingCartDao;
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
}
