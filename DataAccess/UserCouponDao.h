//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_USERCOUPONDAO_H
#define E_COMMERCE_USERCOUPONDAO_H

#include <map>
#include "IUserCouponDao.h"

namespace DataAccess {

    class UserCouponDao : public IUserCouponDao {
    private:
        std::string filename;
        std::map<std::string, std::vector<uint64_t>> userCoupons;
    public:
        explicit UserCouponDao(std::string filename);

        ~UserCouponDao() override;

        void addCoupon(std::string username, uint64_t id) override;

        void removeCoupon(std::string username, uint64_t id) override;

        void removeCoupon(uint64_t id) override;

        std::vector<uint64_t> getCoupons(std::string username) override;

        void save() override;

        bool load() override;
    };

} // DataAccess

#endif //E_COMMERCE_USERCOUPONDAO_H
