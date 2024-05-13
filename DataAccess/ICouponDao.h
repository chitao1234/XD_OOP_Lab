//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_ICOUPONDAO_H
#define E_COMMERCE_ICOUPONDAO_H

#include <cstdint>
#include <vector>
#include "DataType/Coupon.h"

namespace DataAccess {
    class ICouponDao {
    public:
        virtual ~ICouponDao() = default;

        virtual bool containCoupon(uint64_t id) = 0;

        virtual void addCoupon(const DataType::Coupon &coupon) = 0;

        virtual void removeCoupon(uint64_t id) = 0;

        virtual void updateCoupon(const DataType::Coupon &coupon) = 0;

        virtual DataType::Coupon getCoupon(uint64_t id) = 0;

        virtual std::vector<DataType::Coupon> getCoupons() = 0;

        virtual uint64_t nextId() = 0;

        virtual void save() = 0;

        virtual bool load() = 0;
    };

} // DataAccess

#endif //E_COMMERCE_ICOUPONDAO_H
