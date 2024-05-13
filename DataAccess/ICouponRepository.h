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

    class ICouponRepository {
    public:
        virtual ~ICouponRepository() = default;

        virtual void addCoupon(DataType::Coupon coupon) = 0;

        virtual void addCouponToUser(std::string username, uint64_t couponId) = 0;

        virtual void removeCoupon(uint64_t couponId) = 0;

        virtual void removeCouponFromUser(std::string username, uint64_t couponId) = 0;

        virtual std::vector<DataType::Coupon> getUserCoupons(std::string username) = 0;

        virtual std::vector<DataType::Coupon> getCoupons() = 0;
    };

} // DataAccess

#endif //E_COMMERCE_IUSERCOUPONREPOSITORY_H
