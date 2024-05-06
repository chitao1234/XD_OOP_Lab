//
// Created by chi on 24/05/05.
//

#include <stdexcept>
#include <utility>
#include "ShoppingCartRepository.h"
#include "ShoppingCartDao.h"

std::vector<std::pair<Product, long>> ShoppingCartRepository::listProducts() {
    std::vector<std::pair<Product, long>> products;
    for (auto &productId: shoppingCartDao->listProductIds(username)) {
        products.emplace_back(productRepository.getProduct(productId.first).value(), productId.second);
    }
    return products;
}

ShoppingCartRepository::ShoppingCartRepository(IProductRepository &productRepository, std::string username)
        : username(std::move(username)), productRepository(productRepository),
          shoppingCartDao(new ShoppingCartDao("shopping_cart.csv")) {
}

ShoppingCartRepository::~ShoppingCartRepository() {
    delete shoppingCartDao;
}

void ShoppingCartRepository::addProduct(uint64_t productId, long quantity) {
    long originalQuantity = shoppingCartDao->getProductQuantity(username, productId);
    if (originalQuantity < 0) throw std::runtime_error("Product not found in cart");
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
