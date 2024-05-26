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

    class CouponRepository : public ICouponRepository {
    private:
        ICouponDao *couponDao;
        IUserCouponDao *userCouponDao;
    public:
        explicit CouponRepository(IDaoFactory &daoFactory);

        ~CouponRepository() override;

        void addCoupon(DataType::Coupon coupon) override;

        void addCouponToUser(std::string username, uint64_t couponId) override;

        bool addCouponToUser(std::string username, std::string couponCode) override;

        void removeCoupon(uint64_t couponId) override;

        void removeCouponFromUser(std::string username, uint64_t couponId) override;

        std::vector<DataType::Coupon> getUserCoupons(std::string username) override;

        std::vector<DataType::Coupon> getCoupons() override;
    };

} // DataAccess

#endif //E_COMMERCE_COUPONREPOSITORY_H
