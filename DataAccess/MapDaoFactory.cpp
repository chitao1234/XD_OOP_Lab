//
// Created by chi on 24/05/26.
//

#include "MapDaoFactory.h"
#include "MapUserDao.h"
#include "MapProductDao.h"
#include "MapCouponDao.h"
#include "ShoppingCartDao.h"
#include "MapUserCouponDao.h"
#include "MapOrderDao.h"
#include "MapProductOrderDao.h"
#include "MapCategoryDao.h"

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
        return new MapUserCouponDao("user_coupon.csv");
    }

    IOrderDao *MapDaoFactory::getOrderDao() {
        return new MapOrderDao("order.csv");
    }

    IProductOrderDao *MapDaoFactory::getProductOrderDao() {
        return new MapProductOrderDao("product_order.csv");
    }

    ICategoryDao *MapDaoFactory::getCategoryDao() {
        return new MapCategoryDao("category.csv");
    }
} // DataAccess