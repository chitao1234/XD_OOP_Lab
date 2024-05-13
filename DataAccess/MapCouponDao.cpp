//
// Created by chi on 24/05/12.
//

#include <stdexcept>
#include <fstream>
#include "MapCouponDao.h"

namespace DataAccess {
    MapCouponDao::MapCouponDao(std::string filename) : nextIdValue(0), filename(std::move(filename)) {
        // Load data from file
        MapCouponDao::load();
    }

    MapCouponDao::~MapCouponDao() {
        // Save data to file
        MapCouponDao::save();
    }

    bool MapCouponDao::containCoupon(uint64_t id) {
        return coupons.find(id) != coupons.end();
    }

    void MapCouponDao::addCoupon(const DataType::Coupon &coupon) {
        if (containCoupon(coupon.getId())) {
            throw std::runtime_error("Coupon already exists");
        }
        coupons.insert({coupon.getId(), coupon});
    }

    void MapCouponDao::removeCoupon(uint64_t id) {
        if (!containCoupon(id)) {
            throw std::runtime_error("Coupon not found");
        }
        coupons.erase(id);
    }

    void MapCouponDao::updateCoupon(const DataType::Coupon &coupon) {
        coupons.at(coupon.getId()) = coupon;
    }

    DataType::Coupon MapCouponDao::getCoupon(uint64_t id) {
        return coupons.at(id);
    }

    std::vector<DataType::Coupon> MapCouponDao::getCoupons() {
        std::vector<DataType::Coupon> result;
        result.reserve(coupons.size());
        for (const auto &pair: coupons) {
            result.push_back(pair.second);
        }
        return result;
    }

    uint64_t MapCouponDao::nextId() {
        return nextIdValue++;
    }

    void MapCouponDao::save() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file " + filename);
        }
        for (const auto &pair: coupons) {
            file << DataType::Coupon::serialize(pair.second) << std::endl;
        }
    }

    bool MapCouponDao::load() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        coupons.clear();
        nextIdValue = 0;
        std::string line;
        while (std::getline(file, line)) {
            DataType::Coupon coupon = DataType::Coupon::deserialize(line);
            coupons.insert({coupon.getId(), coupon});
            nextIdValue = std::max(nextIdValue, coupon.getId() + 1);
        }
        return true;
    }
} // DataAccess