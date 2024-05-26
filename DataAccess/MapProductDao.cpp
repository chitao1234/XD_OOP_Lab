//
// Created by chi on 24/04/28.
//

#include "MapProductDao.h"

#include <utility>
#include <stdexcept>
#include <fstream>

namespace DataAccess {
    using DataType::Product;

    MapProductDao::MapProductDao(std::string filename) : lastId(0), filename(std::move(filename)) {
        MapProductDao::load();
    }

    MapProductDao::~MapProductDao() {
        MapProductDao::save();
    }

    bool MapProductDao::containProduct(uint64_t id) {
        return products.find(id) != products.end();
    }

    void MapProductDao::addProduct(const Product &product) {
        if (containProduct(product.getId())) {
            throw std::runtime_error("Product already exists");
        }
        products.insert({product.getId(), product});
    }


    void MapProductDao::removeProduct(uint64_t id) {
        if (!containProduct(id)) {
            throw std::runtime_error("Product not found");
        }
        products.erase(id);
    }

    void MapProductDao::updateProduct(const Product &product) {
        products.at(product.getId()) = product;
    }

    Product MapProductDao::getProduct(uint64_t id) {
        return products.at(id);
    }

    std::vector <Product> MapProductDao::getProducts() {
        std::vector <Product> result;
        result.reserve(products.size());
        for (const auto &pair: products) {
            result.push_back(pair.second);
        }
        return result;
    }

    std::vector <Product> MapProductDao::getProducts(std::string query) {
        std::vector <Product> result;
        for (const auto &pair: products) {
            if (pair.second.getName().find(query) != std::string::npos) {
                result.push_back(pair.second);
            }
        }
        return result;
    }

    void MapProductDao::save() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file " + filename);
        }
        for (const auto &pair: products) {
            file << Product::serialize(pair.second) << '\n';
        }
        file.close();
    }

    bool MapProductDao::load() {
        std::ifstream file(filename);
        if (file.bad()) {
            return false;
        }
        products.clear();
        std::string line;
        while (std::getline(file, line)) {
            Product product = Product::deserialize(line);
            lastId = std::max(lastId, product.getId());
            products.insert({product.getId(), product});
        }
        file.close();
        return true;
    }

    uint64_t MapProductDao::nextId() {
        return ++lastId;
    }
}
