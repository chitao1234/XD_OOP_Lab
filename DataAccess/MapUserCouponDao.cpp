//
// Created by chi on 24/05/12.
//

#include "MapUserCouponDao.h"

#include <algorithm>
#include <fstream>
#include <sstream>

namespace DataAccess {
    // 构造时加载数据
    MapUserCouponDao::MapUserCouponDao(std::string filename) : filename(std::move(filename)) {
        MapUserCouponDao::load();
    }

    // 析构时保存数据
    MapUserCouponDao::~MapUserCouponDao() {
        MapUserCouponDao::save();
    }

    void MapUserCouponDao::addCoupon(std::string username, uint64_t id) {
        userCoupons[username].push_back(id);
    }

    void MapUserCouponDao::removeCoupon(std::string username, uint64_t id) {
        auto it = std::find(userCoupons[username].begin(), userCoupons[username].end(), id);
        if (it != userCoupons[username].end()) {
            userCoupons[username].erase(it);
        }
    }

    std::vector<uint64_t> MapUserCouponDao::getCoupons(std::string username) {
        return userCoupons[username];
    }

    void MapUserCouponDao::save() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file " + filename);
        }
        // 采用csv格式保存数据，逗号分隔
        for (const auto &userCoupon: userCoupons) {
            for (const auto &couponId: userCoupon.second) {
                file << userCoupon.first << ',' << couponId << '\n';
            }
        }
    }

    bool MapUserCouponDao::load() {
        std::ifstream file(filename);
        if (!file.is_open()) return false;
        userCoupons.clear();

        std::string line;
        // 采用csv格式读取数据
        while (std::getline(file, line)) {
            std::string username, id;
            std::istringstream iss(line);
            std::getline(iss, username, ',');
            std::getline(iss, id, ',');
            userCoupons[username].push_back(std::stoull(id));
        }
        return true;
    }

    void MapUserCouponDao::removeCoupon(uint64_t id) {
        for (auto &userCoupon: userCoupons) {
            userCoupon.second.erase(std::remove(userCoupon.second.begin(), userCoupon.second.end(), id),
                                    userCoupon.second.end());
        }
    }
} // DataAccess