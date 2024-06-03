//
// Created by chi on 24/05/13.
//

#include "CouponRepository.h"

namespace DataAccess {
    // 使用数据访问对象工厂初始化数据访问对象
    CouponRepository::CouponRepository(IDaoFactory &daoFactory) :
            couponDao(daoFactory.getCouponDao()),
            userCouponDao(daoFactory.getUserCouponDao()) {
    }

    CouponRepository::~CouponRepository() {
        delete couponDao;
        delete userCouponDao;
    }

    void CouponRepository::addCoupon(DataType::Coupon coupon) {
        // 重新生成优惠券ID
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
        // 进行多表查询关联操作
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