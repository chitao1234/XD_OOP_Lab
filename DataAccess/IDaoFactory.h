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
    class IDaoFactory {
    public:
        virtual ~IDaoFactory() = default;

        virtual IUserDao<DataType::NormalUser> *getUserDao() = 0;

        virtual IUserDao<DataType::AdminUser> *getAdminDao() = 0;

        virtual IProductDao *getProductDao() = 0;

        virtual ICouponDao *getCouponDao() = 0;

        virtual IUserCouponDao *getUserCouponDao() = 0;

        virtual IShoppingCartDao *getShoppingCartDao() = 0;

        virtual IOrderDao *getOrderDao() = 0;

        virtual IProductOrderDao *getProductOrderDao() = 0;

        virtual ICategoryDao *getCategoryDao() = 0;
    };
}


#endif //E_COMMERCE_IDAOFACTORY_H
