//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_MAPDAOFACTORY_H
#define E_COMMERCE_MAPDAOFACTORY_H

#include "IDaoFactory.h"


namespace DataAccess {

    class MapDaoFactory: public IDaoFactory {
    public:
        IUserDao<DataType::NormalUser> *getUserDao() override;

        IUserDao<DataType::AdminUser> *getAdminDao() override;

        IProductDao *getProductDao() override;

        ICouponDao *getCouponDao() override;

        IUserCouponDao *getUserCouponDao() override;

        IShoppingCartDao *getShoppingCartDao() override;

        IOrderDao *getOrderDao() override;

        IProductOrderDao *getProductOrderDao() override;
    };

} // DataAccess

#endif //E_COMMERCE_MAPDAOFACTORY_H
