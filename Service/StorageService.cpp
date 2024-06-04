//
// Created by chi on 24/05/06.
//

#include <stdexcept>
#include "StorageService.h"

namespace Service {
    DataAccess::IProductRepository &StorageService::getProductRepository() {
        if (!productRepository)
            productRepository = getRepositoryFactory().getProductRepository();
        return *productRepository;
    }

    DataAccess::IUserRepository &StorageService::getUserRepository() {
        if (!userRepository)
            userRepository = getRepositoryFactory().getUserRepository();
        return *userRepository;
    }

    DataAccess::ICouponRepository &StorageService::getCouponRepository() {
        if (!couponRepository)
            couponRepository = getRepositoryFactory().getCouponRepository();
        return *couponRepository;
    }

    void StorageService::setRepositoryFactory(DataAccess::IRepositoryFactory *repositoryFactory) {
        this->repositoryFactory = repositoryFactory;
    }

    DataAccess::IRepositoryFactory &StorageService::getRepositoryFactory() const {
        if (!repositoryFactory)
            throw std::runtime_error("Repository factory not set");
        return *repositoryFactory;
    }
}
