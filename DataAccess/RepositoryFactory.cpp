//
// Created by chi on 24/05/26.
//

#include "RepositoryFactory.h"
#include "ProductRepository.h"
#include "UserRepository.h"
#include "CouponRepository.h"
#include "CartOrderRepository.h"

namespace DataAccess {
    IProductRepository *RepositoryFactory::getProductRepository() {
        return new ProductRepository(daoFactory);
    }

    IUserRepository *RepositoryFactory::getUserRepository() {
        return new UserRepository(daoFactory);
    }

    ICouponRepository *RepositoryFactory::getCouponRepository() {
        return new CouponRepository(daoFactory);
    }

    ICartOrderRepository *
    RepositoryFactory::getCartOrderRepository(IProductRepository &productRepository, std::string username) {
        return new CartOrderRepository(daoFactory, productRepository, username);
    }

    RepositoryFactory::RepositoryFactory(IDaoFactory &daoFactory) : daoFactory(daoFactory) {}
} // DataAccess