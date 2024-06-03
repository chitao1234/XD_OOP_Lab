//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_IREPOSITORYFACTORY_H
#define E_COMMERCE_IREPOSITORYFACTORY_H

#include "IProductRepository.h"
#include "IUserRepository.h"
#include "ICouponRepository.h"
#include "ICartOrderRepository.h"

namespace DataAccess {
    // 仓储工厂接口，用于创建仓储对象，隐藏具体实现，业务服务层使用
    class IRepositoryFactory {
    public:
        // 接口需要使用虚析构函数
        virtual ~IRepositoryFactory() = default;

        // 获取商品仓储对象
        virtual IProductRepository *getProductRepository() = 0;

        // 获取用户仓储对象
        virtual IUserRepository *getUserRepository() = 0;

        // 获取优惠券仓储对象
        virtual ICouponRepository *getCouponRepository() = 0;

        // 获取购物车订单仓储对象
        virtual ICartOrderRepository *
        getCartOrderRepository(IProductRepository &productRepository, std::string username) = 0;
    };

} // DataAccess

#endif //E_COMMERCE_IREPOSITORYFACTORY_H
