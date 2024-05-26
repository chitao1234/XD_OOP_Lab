//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_MAPREPOSITORYFACTORY_H
#define E_COMMERCE_MAPREPOSITORYFACTORY_H

#include "IRepositoryFactory.h"
#include "IDaoFactory.h"

namespace DataAccess {

    class MapRepositoryFactory : public IRepositoryFactory {
    public:
        MapRepositoryFactory(IDaoFactory &daoFactory);

        IProductRepository *getProductRepository() override;

        IUserRepository *getUserRepository() override;

        ICouponRepository *getCouponRepository() override;

        ICartOrderRepository *
        getCartOrderRepository(IProductRepository &productRepository, std::string username) override;

    private:
        IDaoFactory &daoFactory;
    };

} // DataAccess

#endif //E_COMMERCE_MAPREPOSITORYFACTORY_H
