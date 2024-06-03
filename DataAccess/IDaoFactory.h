//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_IDAOFACTORY_H
#define E_COMMERCE_IDAOFACTORY_H


#include "IUserDao.h"
#include "DataType/NormalUser.h"
#include "DataType/AdminUser.h"
#include "IProductDao.h"
#include "ICouponDao.h"
#include "IShoppingCartDao.h"
#include "IUserCouponDao.h"
#include "IOrderDao.h"
#include "IProductOrderDao.h"
#include "ICategoryDao.h"

namespace DataAccess {
    // 数据访问对象工厂接口，用于创建数据访问对象，隐藏具体实现，仓储层使用
    class IDaoFactory {
    public:
        // 接口需要使用虚析构函数
        virtual ~IDaoFactory() = default;

        // 获取普通用户数据访问对象
        virtual IUserDao<DataType::NormalUser> *getUserDao() = 0;

        // 获取管理员用户数据访问对象
        virtual IUserDao<DataType::AdminUser> *getAdminDao() = 0;

        // 获取商品数据访问对象
        virtual IProductDao *getProductDao() = 0;

        // 获取优惠券数据访问对象
        virtual ICouponDao *getCouponDao() = 0;

        // 获取用户优惠券关联数据访问对象
        virtual IUserCouponDao *getUserCouponDao() = 0;

        // 获取购物车数据访问对象
        virtual IShoppingCartDao *getShoppingCartDao() = 0;

        // 获取订单数据访问对象
        virtual IOrderDao *getOrderDao() = 0;

        // 获取商品信息数据访问对象
        virtual IProductOrderDao *getProductOrderDao() = 0;

        // 获取商品分类数据访问对象
        virtual ICategoryDao *getCategoryDao() = 0;
    };
}


#endif //E_COMMERCE_IDAOFACTORY_H
