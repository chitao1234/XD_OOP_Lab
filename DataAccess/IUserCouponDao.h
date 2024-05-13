//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_IUSERCOUPONDAO_H
#define E_COMMERCE_IUSERCOUPONDAO_H

#include <vector>
#include <string>
#include <cstdint>
#include "DataType/Coupon.h"

namespace DataAccess {

    class IUserCouponDao {
    public:
        virtual ~IUserCouponDao() = default;

        virtual void addCoupon(std::string username, uint64_t id) = 0;

        virtual void removeCoupon(std::string username, uint64_t id) = 0;

        virtual void removeCoupon(uint64_t id) = 0;

        virtual std::vector<uint64_t> getCoupons(std::string username) = 0;

        virtual void save() = 0;

        virtual bool load() = 0;
    };

} // DataAccess

#endif //E_COMMERCE_IUSERCOUPONDAO_H
