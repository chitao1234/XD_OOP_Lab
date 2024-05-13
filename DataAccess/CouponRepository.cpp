//
// Created by chi on 24/05/13.
//

#include "CouponRepository.h"
#include "UserCouponDao.h"
#include "MapCouponDao.h"

namespace DataAccess {
    CouponRepository::CouponRepository() :
            couponDao(new MapCouponDao("coupon.csv")),
            userCouponDao(new UserCouponDao("user_coupon.csv")) {
    }

    CouponRepository::~CouponRepository() {
        delete couponDao;
        delete userCouponDao;
    }

    void CouponRepository::addCoupon(DataType::Coupon coupon) {
        coupon.setId(couponDao->nextId());
        couponDao->addCoupon(coupon);
        couponDao->save();
    }

    void CouponRepository::addCouponToUser(std::string username, uint64_t couponId) {
        userCouponDao->addCoupon(username, couponId);
        userCouponDao->save();
    }

    void CouponRepository::removeCoupon(uint64_t couponId) {
        couponDao->removeCoupon(couponId);
        userCouponDao->removeCoupon(couponId);
        couponDao->save();
        userCouponDao->save();
    }

    void CouponRepository::removeCouponFromUser(std::string username, uint64_t couponId) {
        userCouponDao->removeCoupon(username, couponId);
        userCouponDao->save();
    }

    std::vector<DataType::Coupon> CouponRepository::getUserCoupons(std::string username) {
        std::vector<DataType::Coupon> coupons;
        for (auto &couponId: userCouponDao->getCoupons(username)) {
            coupons.push_back(couponDao->getCoupon(couponId));
        }
        return coupons;
    }

    std::vector<DataType::Coupon> CouponRepository::getCoupons() {
        return couponDao->getCoupons();
    }

    bool CouponRepository::addCouponToUser(std::string username, std::string couponCode) {
        if (!couponDao->containCoupon(couponCode)) return false;
        auto coupon = couponDao->getCoupon(couponCode);
        userCouponDao->addCoupon(username, coupon.getId());
        userCouponDao->save();
        return true;
    }
} // DataAccess