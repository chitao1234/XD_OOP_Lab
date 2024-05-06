//
// Created by chi on 24/05/05.
//

#include "ShoppingCartDao.h"

#include <utility>
#include <fstream>
#include <sstream>

std::vector<std::pair<uint64_t, long>> ShoppingCartDao::listProductIds(std::string username) {
    return carts[username];
}

ShoppingCartDao::ShoppingCartDao(std::string filename) : filename(std::move(filename)) {
    ShoppingCartDao::load();
}

ShoppingCartDao::~ShoppingCartDao() {
    ShoppingCartDao::save();
}

void ShoppingCartDao::removeProduct(std::string username, uint64_t productId) {
    auto &cart = carts[username];
    for (auto iter = cart.begin(); iter != cart.end(); ++iter) {
        if (iter->first == productId) {
            cart.erase(iter);
            return;
        }
    }
}

void ShoppingCartDao::updateProductQuantity(std::string username, uint64_t productId, long quantity) {
    auto &cart = carts[username];
    for (auto &product: cart) {
        if (product.first == productId) {
            product.second = quantity;
            return;
        }
    }
    cart.emplace_back(productId, quantity);
}

void ShoppingCartDao::clearCart(std::string username) {
    carts[username].clear();
}

void ShoppingCartDao::save() {
    std::ofstream ofs(filename);
    for (const auto &cart: carts) {
        for (const auto &product: cart.second) {
            ofs << cart.first << ',' << product.first << ',' << product.second << '\n';
        }
    }
    ofs.close();
}

bool ShoppingCartDao::load() {
    std::ifstream ifs(filename);
    if (!ifs) return false;
    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        std::string currentUsername;
        uint64_t productId;
        long quantity;
        std::getline(iss, currentUsername, ',');
        iss >> productId;
        iss.ignore(1);
        iss >> quantity;
        carts[currentUsername].emplace_back(productId, quantity);
    }
    ifs.close();
    return true;
}

long ShoppingCartDao::getProductQuantity(std::string username, uint64_t productId) {
    for (const auto &product: carts[username]) {
        if (product.first == productId) {
            return product.second;
        }
    }
    return -1;
}
