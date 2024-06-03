//
// Created by chi on 24/04/28.
//

#include "MapProductDao.h"

#include <stdexcept>
#include <fstream>

namespace DataAccess {
    // 创建时加载数据
    MapProductDao::MapProductDao(std::string filename) : lastId(0), filename(std::move(filename)) {
        MapProductDao::load();
    }

    // 销毁时保存数据
    MapProductDao::~MapProductDao() {
        MapProductDao::save();
    }

    bool MapProductDao::containProduct(uint64_t id) {
        return products.find(id) != products.end();
    }

    void MapProductDao::addProduct(const DataType::Product &product) {
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

    void MapProductDao::updateProduct(const DataType::Product &product) {
        products.at(product.getId()) = product;
    }

    DataType::Product MapProductDao::getProduct(uint64_t id) {
        return products.at(id);
    }

    std::vector <DataType::Product> MapProductDao::getProducts() {
        std::vector <DataType::Product> result;
        result.reserve(products.size());
        for (const auto &pair: products) {
            result.push_back(pair.second);
        }
        return result;
    }

    std::vector <DataType::Product> MapProductDao::getProducts(std::string query) {
        std::vector <DataType::Product> result;
        for (const auto &pair: products) {
            // 使用商品名进行模糊匹配
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

        // 使用商品的序列化方法保存数据
        for (const auto &pair: products) {
            file << DataType::Product::serialize(pair.second) << '\n';
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
        // 使用商品的反序列化方法加载数据
        while (std::getline(file, line)) {
            DataType::Product product = DataType::Product::deserialize(line);
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
