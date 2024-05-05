//
// Created by chi on 24/04/29.
//

#include "MapProductRepository.h"
#include "MapProductDao.h"

MapProductRepository::MapProductRepository() : productDao(new MapProductDao("products.csv")) {}

MapProductRepository::~MapProductRepository() {
    delete productDao;
}

bool MapProductRepository::addProduct(std::string name, std::string description, double price, long remainingStock) {
    productDao->addProduct(Product(productDao->nextId(), name, description, price, remainingStock));
    productDao->save();
    return true;
}

std::optional<Product> MapProductRepository::getProduct(uint64_t productId) {
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
    productDao->save();
    return true;
}

bool MapProductRepository::deleteProduct(uint64_t productId) {
    if (!productDao->containProduct(productId)) {
        return false;
    }
    productDao->removeProduct(productId);
    productDao->save();
    return true;
}

std::vector<Product> MapProductRepository::listProducts() {
    return productDao->getProducts();
}
