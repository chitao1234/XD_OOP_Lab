//
// Created by chi on 24/05/12.
//

#include "UserCouponDao.h"

#include <algorithm>
#include <fstream>
#include <sstream>

namespace DataAccess {
    UserCouponDao::UserCouponDao(std::string filename) : filename(std::move(filename)) {
        UserCouponDao::load();
    }

    UserCouponDao::~UserCouponDao() {
        UserCouponDao::save();
    }

    void UserCouponDao::addCoupon(std::string username, uint64_t id) {
        userCoupons[username].push_back(id);
    }

    void UserCouponDao::removeCoupon(std::string username, uint64_t id) {
        auto it = std::find(userCoupons[username].begin(), userCoupons[username].end(), id);
        if (it != userCoupons[username].end()) {
            userCoupons[username].erase(it);
        }
    }

    std::vector<uint64_t> UserCouponDao::getCoupons(std::string username) {
        return userCoupons[username];
    }

    void UserCouponDao::save() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file " + filename);
        }
        for (const auto &userCoupon: userCoupons) {
            for (const auto &couponId: userCoupon.second) {
                file << userCoupon.first << ',' << couponId << '\n';
            }
        }
    }

    bool UserCouponDao::load() {
        std::ifstream file(filename);
        if (!file.is_open()) return false;
        userCoupons.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::string username, id;
            std::istringstream iss(line);
            std::getline(iss, username, ',');
            std::getline(iss, id, ',');
            userCoupons[username].push_back(std::stoull(id));
        }
        return true;
    }

    void UserCouponDao::removeCoupon(uint64_t id) {
        for (auto &userCoupon: userCoupons) {
            userCoupon.second.erase(std::remove(userCoupon.second.begin(), userCoupon.second.end(), id),
                                    userCoupon.second.end());
        }
    }
} // DataAccess