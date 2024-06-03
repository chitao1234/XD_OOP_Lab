//
// Created by chi on 24/05/12.
//

#include <stdexcept>
#include <fstream>
#include "MapCouponDao.h"

namespace DataAccess {
    // 构造时加载数据
    MapCouponDao::MapCouponDao(std::string filename) : nextIdValue(0), filename(std::move(filename)) {
        MapCouponDao::load();
    }

    // 析构时保存数据
    MapCouponDao::~MapCouponDao() {
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
            // 调用优惠券数据对象的序列化方法
            file << DataType::Coupon::serialize(pair.second) << std::endl;
        }
    }

    bool MapCouponDao::load() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        coupons.clear();
        nextIdValue = 1;
        std::string line;
        while (std::getline(file, line)) {
            // 调用优惠券数据对象的反序列化方法
            DataType::Coupon coupon = DataType::Coupon::deserialize(line);
            coupons.insert({coupon.getId(), coupon});
            nextIdValue = std::max(nextIdValue, coupon.getId() + 1);
        }
        return true;
    }

    bool MapCouponDao::containCoupon(std::string code) {
        if (code.empty()) return false;
        for (const auto &pair: coupons) {
            if (pair.second.getCode() == code) {
                return true;
            }
        }
        return false;
    }

    DataType::Coupon MapCouponDao::getCoupon(std::string code) {
        if (code.empty()) {
            throw std::invalid_argument("Code cannot be empty");
        }
        // 遍历map搜索
        for (const auto &pair: coupons) {
            if (pair.second.getCode() == code) {
                return pair.second;
            }
        }
        throw std::runtime_error("Coupon not found");
    }
} // DataAccess