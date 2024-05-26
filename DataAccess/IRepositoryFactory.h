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

    class IRepositoryFactory {
    public:
        virtual ~IRepositoryFactory() = default;

        virtual IProductRepository *getProductRepository() = 0;

        virtual IUserRepository *getUserRepository() = 0;

        virtual ICouponRepository *getCouponRepository() = 0;

        virtual ICartOrderRepository *
        getCartOrderRepository(IProductRepository &productRepository, std::string username) = 0;
    };

} // DataAccess

#endif //E_COMMERCE_IREPOSITORYFACTORY_H
