//
// Created by chi on 24/05/26.
//

#include "MapDaoFactory.h"
#include "MapUserDao.h"
#include "MapProductDao.h"
#include "MapCouponDao.h"
#include "ShoppingCartDao.h"
#include "UserCouponDao.h"

namespace DataAccess {
    IUserDao<DataType::NormalUser> *MapDaoFactory::getUserDao() {
        return new MapUserDao<DataType::NormalUser>("users.csv");
    }

    IUserDao<DataType::AdminUser> *MapDaoFactory::getAdminDao() {
        return new MapUserDao<DataType::AdminUser>("admin.csv");
    }

    IProductDao *MapDaoFactory::getProductDao() {
        return new MapProductDao("products.csv");
    }

    ICouponDao *MapDaoFactory::getCouponDao() {
        return new MapCouponDao("coupon.csv");
    }

    IShoppingCartDao *MapDaoFactory::getShoppingCartDao() {
        return new ShoppingCartDao("shopping_cart.csv");
    }

    IUserCouponDao *MapDaoFactory::getUserCouponDao() {
        return new UserCouponDao("user_coupon.csv");
    }
} // DataAccess