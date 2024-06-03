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
    // 用户优惠券数据访问对象接口，用于底层数据存储访问
    class IUserCouponDao {
    public:
        // 接口需要使用虚析构函数
        virtual ~IUserCouponDao() = default;

        // 向用户添加优惠券
        virtual void addCoupon(std::string username, uint64_t id) = 0;

        // 移除用户的优惠券
        virtual void removeCoupon(std::string username, uint64_t id) = 0;

        // 移除所有用户的指定优惠券
        virtual void removeCoupon(uint64_t id) = 0;

        // 获取用户的优惠券
        virtual std::vector<uint64_t> getCoupons(std::string username) = 0;

        // 保存数据
        virtual void save() = 0;

        // 加载数据
        virtual bool load() = 0;
    };

} // DataAccess

#endif //E_COMMERCE_IUSERCOUPONDAO_H
