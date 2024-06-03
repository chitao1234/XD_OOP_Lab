//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_REPOSITORYFACTORY_H
#define E_COMMERCE_REPOSITORYFACTORY_H

#include "IRepositoryFactory.h"
#include "IDaoFactory.h"

namespace DataAccess {
    // 数据仓储工厂，用于创建数据仓储对象，使用数据访问对象工厂
    class RepositoryFactory : public IRepositoryFactory {
    public:
        explicit RepositoryFactory(IDaoFactory &daoFactory);

        // 获取商品数据仓储
        IProductRepository *getProductRepository() override;

        // 获取用户数据仓储
        IUserRepository *getUserRepository() override;

        // 获取优惠券数据仓储
        ICouponRepository *getCouponRepository() override;

        // 获取购物车、订单信息数据仓储
        ICartOrderRepository *
        getCartOrderRepository(IProductRepository &productRepository, std::string username) override;

    private:
        IDaoFactory &daoFactory;
    };

} // DataAccess

#endif //E_COMMERCE_REPOSITORYFACTORY_H
