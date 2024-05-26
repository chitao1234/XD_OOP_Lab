//
// Created by chi on 24/05/26.
//

#include <fstream>
#include <sstream>
#include "MapProductOrderDao.h"

namespace DataAccess {
    MapProductOrderDao::MapProductOrderDao(std::string filename)
            : filename(std::move(filename)) {
        MapProductOrderDao::load();
    }

    MapProductOrderDao::~MapProductOrderDao() {
        MapProductOrderDao::save();
    }

    void MapProductOrderDao::addProductToOrder(uint64_t orderId, uint64_t productId, long quantity) {
        orderProductMap[orderId].emplace_back(productId, quantity);
    }

    void MapProductOrderDao::removeProductFromOrder(uint64_t orderId, uint64_t productId) {
        auto &products = orderProductMap[orderId];
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->first == productId) {
                products.erase(it);
                break;
            }
        }
    }

    void MapProductOrderDao::updateProductQuantity(uint64_t orderId, uint64_t productId, long quantity) {
        auto &products = orderProductMap[orderId];
        for (auto &product: products) {
            if (product.first == productId) {
                product.second = quantity;
                break;
            }
        }
    }

    void MapProductOrderDao::clearOrder(uint64_t orderId) {
        orderProductMap.erase(orderId);
    }

    void MapProductOrderDao::save() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file " + filename);
        }
        for (const auto &pair: orderProductMap) {
            for (const auto &product: pair.second) {
                file << pair.first << ',' << product.first << ',' << product.second << '\n';
            }
        }
    }

    bool MapProductOrderDao::load() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        orderProductMap.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string orderId, productId, quantity;
            std::getline(iss, orderId, ',');
            std::getline(iss, productId, ',');
            std::getline(iss, quantity, ',');
            orderProductMap[std::stoull(orderId)].emplace_back(std::stoull(productId), std::stol(quantity));
        }
        return true;
    }

    std::vector<std::pair<uint64_t, long>> MapProductOrderDao::getProducts(uint64_t orderId) {
        return orderProductMap[orderId];
    }


} // DataAccess