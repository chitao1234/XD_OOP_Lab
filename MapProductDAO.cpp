//
// Created by chi on 24/04/28.
//

#include "MapProductDAO.h"

#include <utility>
#include <stdexcept>
#include <fstream>

MapProductDAO::MapProductDAO(std::string filename) : filename(std::move(filename)) {
}

bool MapProductDAO::containProduct(uint64_t id) {
    return products.find(id) != products.end();
}

void MapProductDAO::addProduct(const Product &product) {
    if (containProduct(product.getId())) {
        throw std::runtime_error("Product already exists");
    }
    products.insert({product.getId(), product});
}


void MapProductDAO::removeProduct(uint64_t id) {
    if (!containProduct(id)) {
        throw std::runtime_error("Product not found");
    }
    products.erase(id);
}

void MapProductDAO::updateProduct(const Product &product) {
    products.at(product.getId()) = product;
}

Product MapProductDAO::getProduct(uint64_t id) {
    return products.at(id);
}

std::vector<Product> MapProductDAO::getProducts() {
    std::vector<Product> result;
    result.reserve(products.size());
    for (const auto &pair : products) {
        result.push_back(pair.second);
    }
    return result;
}

std::vector<Product> MapProductDAO::getProducts(std::string query) {
    std::vector<Product> result;
    for (const auto &pair : products) {
        if (pair.second.getName().find(query) != std::string::npos) {
            result.push_back(pair.second);
        }
    }
    return result;
}

void MapProductDAO::save() {
    std::ofstream file(filename);
    for (const auto &pair : products) {
        file << Product::serialize(pair.second) << '\n';
    }
}

bool MapProductDAO::load() {
    std::ifstream file(filename);
    if (file.bad()) {
        return false;
    }
    products.clear();
    std::string line;
    while (std::getline(file, line)) {
        Product product = Product::deserialize(line);
        products.insert({product.getId(), product});
    }
    return true;
}
