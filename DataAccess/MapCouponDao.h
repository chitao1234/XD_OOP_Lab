//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_MAPCOUPONDAO_H
#define E_COMMERCE_MAPCOUPONDAO_H

#include <map>
#include "ICouponDao.h"

namespace DataAccess {

    class MapCouponDao : public ICouponDao {
    public:
        MapCouponDao(std::string filename);

        ~MapCouponDao() override;

        bool containCoupon(uint64_t id) override;

        bool containCoupon(std::string code) override;

        void addCoupon(const DataType::Coupon &coupon) override;

        void removeCoupon(uint64_t id) override;

        void updateCoupon(const DataType::Coupon &coupon) override;

        DataType::Coupon getCoupon(uint64_t id) override;

        DataType::Coupon getCoupon(std::string code) override;

        std::vector<DataType::Coupon> getCoupons() override;

        uint64_t nextId() override;

        void save() override;

        bool load() override;
    private:
        std::map<uint64_t, DataType::Coupon> coupons;
        uint64_t nextIdValue;
        std::string filename;
    };

} // DataAccess

#endif //E_COMMERCE_MAPCOUPONDAO_H
