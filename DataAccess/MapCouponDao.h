//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_MAPCOUPONDAO_H
#define E_COMMERCE_MAPCOUPONDAO_H

#include <map>
#include "ICouponDao.h"

namespace DataAccess {
    // 优惠券数据访问对象，使用map缓存，文件持久化
    class MapCouponDao : public ICouponDao {
    public:
        explicit MapCouponDao(std::string filename);

        ~MapCouponDao() override;

        // 判断是否包含某个优惠券ID
        bool containCoupon(uint64_t id) override;

        // 判断是否包含某个优惠券代码
        bool containCoupon(std::string code) override;

        // 添加优惠券
        void addCoupon(const DataType::Coupon &coupon) override;

        // 移除优惠券
        void removeCoupon(uint64_t id) override;

        // 更新优惠券
        void updateCoupon(const DataType::Coupon &coupon) override;

        // 根据优惠券ID获取优惠券
        DataType::Coupon getCoupon(uint64_t id) override;

        // 根据优惠券代码获取优惠券
        DataType::Coupon getCoupon(std::string code) override;

        // 获取所有优惠券
        std::vector<DataType::Coupon> getCoupons() override;

        // 获取下一个优惠券ID
        uint64_t nextId() override;

        // 保存数据
        void save() override;

        // 加载数据
        bool load() override;
    private:
        std::map<uint64_t, DataType::Coupon> coupons;
        uint64_t nextIdValue;
        std::string filename;
    };

} // DataAccess

#endif //E_COMMERCE_MAPCOUPONDAO_H
