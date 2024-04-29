//
// Created by chi on 24/04/29.
//

#include "MapProductRepository.h"
#include "MapProductDAO.h"

MapProductRepository::MapProductRepository() : productDao(new MapProductDAO("products.csv")) {}

bool MapProductRepository::addProduct(const Product &product) {
    if (productDao->containProduct(product.getId())) {
        return false;
    }
    productDao->addProduct(product);
    return true;
}

std::optional<Product> MapProductRepository::getProduct(int productId) {
    if (!productDao->containProduct(productId)) {
        return std::nullopt;
    }
    return productDao->getProduct(productId);
}

bool MapProductRepository::updateProduct(const Product &product) {
    if (!productDao->containProduct(product.getId())) {
        return false;
    }
    productDao->updateProduct(product);
    return true;
}

bool MapProductRepository::deleteProduct(int productId) {
    if (!productDao->containProduct(productId)) {
        return false;
    }
    productDao->removeProduct(productId);
    return true;
}

std::vector<Product> MapProductRepository::listProducts() {
    return productDao->getProducts();
}

