//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_ICOUPONDAO_H
#define E_COMMERCE_ICOUPONDAO_H

#include <cstdint>
#include <vector>
#include "DataType/Coupon.h"

namespace DataAccess {
    // 优惠券数据访问对象接口，不存储用户与优惠券的关系，用于底层数据存储访问
    class ICouponDao {
    public:
        // 接口需要使用虚析构函数
        virtual ~ICouponDao() = default;

        // 判断是否包含某个优惠券ID
        virtual bool containCoupon(uint64_t id) = 0;

        // 判断是否包含某个优惠券码
        virtual bool containCoupon(std::string code) = 0;

        // 添加优惠券
        virtual void addCoupon(const DataType::Coupon &coupon) = 0;

        // 移除优惠券
        virtual void removeCoupon(uint64_t id) = 0;

        // 更新优惠券信息
        virtual void updateCoupon(const DataType::Coupon &coupon) = 0;

        // 获取优惠券，根据ID
        virtual DataType::Coupon getCoupon(uint64_t id) = 0;

        // 获取优惠券，根据优惠券码，用于用户核销
        virtual DataType::Coupon getCoupon(std::string code) = 0;

        // 获取所有优惠券
        virtual std::vector<DataType::Coupon> getCoupons() = 0;

        // 获取下一个优惠券ID
        virtual uint64_t nextId() = 0;

        // 保存数据
        virtual void save() = 0;

        // 加载数据
        virtual bool load() = 0;
    };

} // DataAccess

#endif //E_COMMERCE_ICOUPONDAO_H
