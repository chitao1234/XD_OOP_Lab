//
// Created by chi on 24/05/26.
//

#include "MapRepositoryFactory.h"
#include "MapProductRepository.h"
#include "MapUserRepository.h"
#include "CouponRepository.h"
#include "ShoppingCartRepository.h"

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

    IShoppingCartRepository *
    MapRepositoryFactory::getShoppingCartRepository(IProductRepository &productRepository, std::string username) {
        return new ShoppingCartRepository(daoFactory, productRepository, username);
    }

    MapRepositoryFactory::MapRepositoryFactory(IDaoFactory &daoFactory) : daoFactory(daoFactory) {}
} // DataAccess