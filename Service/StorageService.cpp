//
// Created by chi on 24/05/06.
//

#include <stdexcept>
#include "StorageService.h"

namespace Service {
    using DataAccess::IUserRepository;
    using DataAccess::IProductRepository;

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

    void StorageService::setProductRepository(IProductRepository &productRepository) {
        this->productRepository = &productRepository;
    }

    void StorageService::setUserRepository(IUserRepository &userRepository) {
        this->userRepository = &userRepository;
    }
}
