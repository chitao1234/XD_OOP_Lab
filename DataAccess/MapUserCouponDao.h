//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_MAPUSERCOUPONDAO_H
#define E_COMMERCE_MAPUSERCOUPONDAO_H

#include <map>
#include "IUserCouponDao.h"

namespace DataAccess {
    // 用户-优惠券映射数据访问对象，使用map存储，文件持久化
    class MapUserCouponDao : public IUserCouponDao {
    private:
        std::string filename;
        std::map<std::string, std::vector<uint64_t>> userCoupons;
    public:
        explicit MapUserCouponDao(std::string filename);

        ~MapUserCouponDao() override;

        // 向用户添加优惠券
        void addCoupon(std::string username, uint64_t id) override;

        // 移除用户的优惠券
        void removeCoupon(std::string username, uint64_t id) override;

        // 将所有用户的指定优惠券移除
        void removeCoupon(uint64_t id) override;

        // 获取用户的所有优惠券
        std::vector<uint64_t> getCoupons(std::string username) override;

        // 保存数据
        void save() override;

        // 加载数据
        bool load() override;
    };

} // DataAccess

#endif //E_COMMERCE_MAPUSERCOUPONDAO_H
