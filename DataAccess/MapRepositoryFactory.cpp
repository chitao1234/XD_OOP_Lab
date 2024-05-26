//
// Created by chi on 24/05/26.
//

#include "MapRepositoryFactory.h"
#include "MapProductRepository.h"
#include "MapUserRepository.h"
#include "CouponRepository.h"
#include "CartOrderRepository.h"

namespace DataAccess {
    IProductRepository *MapRepositoryFactory::getProductRepository() {
        return new MapProductRepository(daoFactory);
    }

    IUserRepository *MapRepositoryFactory::getUserRepository() {
        return new MapUserRepository(daoFactory);
    }

    ICouponRepository *MapRepositoryFactory::getCouponRepository() {
        return new CouponRepository(daoFactory);
    }

    ICartOrderRepository *
    MapRepositoryFactory::getCartOrderRepository(IProductRepository &productRepository, std::string username) {
        return new CartOrderRepository(daoFactory, productRepository, username);
    }

    MapRepositoryFactory::MapRepositoryFactory(IDaoFactory &daoFactory) : daoFactory(daoFactory) {}
} // DataAccess