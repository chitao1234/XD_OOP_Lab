//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_MAPDAOFACTORY_H
#define E_COMMERCE_MAPDAOFACTORY_H

#include "IDaoFactory.h"


namespace DataAccess {
    // 数据访问对象工厂的具体实现，使用各个map数据访问对象
    class MapDaoFactory: public IDaoFactory {
    public:
        // 获取用户数据访问对象
        IUserDao<DataType::NormalUser> *getUserDao() override;

        // 获取管理员数据访问对象
        IUserDao<DataType::AdminUser> *getAdminDao() override;

        // 获取商品数据访问对象
        IProductDao *getProductDao() override;

        // 获取优惠券数据访问对象
        ICouponDao *getCouponDao() override;

        // 获取用户优惠券数据访问对象
        IUserCouponDao *getUserCouponDao() override;

        // 获取购物车数据访问对象
        IShoppingCartDao *getShoppingCartDao() override;

        // 获取订单数据访问对象
        IOrderDao *getOrderDao() override;

        // 获取订单商品数据访问对象
        IProductOrderDao *getProductOrderDao() override;

        // 获取商品分类数据访问对象
        ICategoryDao *getCategoryDao() override;
    };

} // DataAccess

#endif //E_COMMERCE_MAPDAOFACTORY_H
