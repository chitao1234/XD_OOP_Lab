//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_IUSERCOUPONREPOSITORY_H
#define E_COMMERCE_IUSERCOUPONREPOSITORY_H

#include <string>
#include <cstdint>
#include <vector>
#include "DataType/Coupon.h"

namespace DataAccess {
    // 用户优惠券数据仓储接口，用于与外界交互
    class ICouponRepository {
    public:
        // 接口需要使用虚析构函数
        virtual ~ICouponRepository() = default;

        // 添加优惠券
        virtual void addCoupon(DataType::Coupon coupon) = 0;

        // 将优惠券添加到用户，管理员发放优惠券时使用
        virtual void addCouponToUser(std::string username, uint64_t couponId) = 0;

        // 将优惠券添加到用户，用户核销优惠券时使用
        virtual bool addCouponToUser(std::string username, std::string couponCode) = 0;

        // 移除优惠券，同时移除用户的优惠券
        virtual void removeCoupon(uint64_t couponId) = 0;

        // 仅移除用户的优惠券
        virtual void removeCouponFromUser(std::string username, uint64_t couponId) = 0;

        // 获取用户的全部优惠券
        virtual std::vector<DataType::Coupon> getUserCoupons(std::string username) = 0;

        // 获取目前所有优惠券
        virtual std::vector<DataType::Coupon> getCoupons() = 0;
    };

} // DataAccess

#endif //E_COMMERCE_IUSERCOUPONREPOSITORY_H
