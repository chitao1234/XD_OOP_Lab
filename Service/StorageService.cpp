//
// Created by chi on 24/05/06.
//

#include <stdexcept>
#include "StorageService.h"

namespace Service {
    using DataAccess::IUserRepository;
    using DataAccess::IProductRepository;
    using DataAccess::ICouponRepository;

    IProductRepository &StorageService::getProductRepository() const {
        if (!productRepository)
            throw std::runtime_error("Product repository not set");
        return *productRepository;
    }

    IUserRepository &StorageService::getUserRepository() const {
        if (!userRepository)
            throw std::runtime_error("User repository not set");
        return *userRepository;
    }

    ICouponRepository &StorageService::getCouponRepository() const {
        if (!couponRepository)
            throw std::runtime_error("Coupon repository not set");
        return *couponRepository;
    }

    void StorageService::setProductRepository(IProductRepository &productRepository) {
        this->productRepository = &productRepository;
    }

    void StorageService::setUserRepository(IUserRepository &userRepository) {
        this->userRepository = &userRepository;
    }

    void StorageService::setCouponRepository(ICouponRepository &couponRepository) {
        this->couponRepository = &couponRepository;
    }

    DataAccess::IDaoFactory &StorageService::getDaoFactory() const {
        if (!daoFactory)
            throw std::runtime_error("DAO factory not set");
        return *daoFactory;
    }

    void StorageService::setDaoFactory(DataAccess::IDaoFactory &daoFactory) {
        this->daoFactory = &daoFactory;
    }
}
