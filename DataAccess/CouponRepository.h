//
// Created by chi on 24/05/13.
//

#ifndef E_COMMERCE_COUPONREPOSITORY_H
#define E_COMMERCE_COUPONREPOSITORY_H

#include "ICouponRepository.h"
#include "IUserCouponDao.h"
#include "ICouponDao.h"
#include "IDaoFactory.h"

namespace DataAccess {
    // 优惠券数据仓储的具体实现，使用底层数据访问对象实现
    class CouponRepository : public ICouponRepository {
    private:
        // 优惠券数据访问对象，用户优惠券关联数据访问对象
        ICouponDao *couponDao;
        IUserCouponDao *userCouponDao;
    public:
        explicit CouponRepository(IDaoFactory &daoFactory);

        ~CouponRepository() override;

        // 添加优惠券
        void addCoupon(DataType::Coupon coupon) override;

        // 将优惠券添加到用户，管理员发放优惠券时使用
        void addCouponToUser(std::string username, uint64_t couponId) override;

        // 将优惠券添加到用户，用户核销优惠券时使用，可能失败
        bool addCouponToUser(std::string username, std::string couponCode) override;

        // 移除优惠券，同时移除用户的优惠券
        void removeCoupon(uint64_t couponId) override;

        // 仅移除用户的优惠券
        void removeCouponFromUser(std::string username, uint64_t couponId) override;

        // 获取用户的全部优惠券
        std::vector<DataType::Coupon> getUserCoupons(std::string username) override;

        // 获取目前所有优惠券
        std::vector<DataType::Coupon> getCoupons() override;
    };

} // DataAccess

#endif //E_COMMERCE_COUPONREPOSITORY_H
