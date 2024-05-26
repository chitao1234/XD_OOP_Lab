//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_STORAGESERVICE_H
#define E_COMMERCE_STORAGESERVICE_H

#include <optional>
#include "SingletonTemplate.h"
#include "DataAccess/IProductRepository.h"
#include "DataAccess/IUserRepository.h"
#include "DataAccess/ICouponRepository.h"
#include "DataAccess/IDaoFactory.h"
#include "DataAccess/IRepositoryFactory.h"


namespace Service {
    class StorageService : public SingletonTemplate<StorageService> {
    public:
        [[nodiscard]] DataAccess::IProductRepository &getProductRepository();

        [[nodiscard]] DataAccess::IUserRepository &getUserRepository();

        [[nodiscard]] DataAccess::ICouponRepository &getCouponRepository();

        [[nodiscard]] DataAccess::IRepositoryFactory &getRepositoryFactory() const;

        void setRepositoryFactory(DataAccess::IRepositoryFactory *repositoryFactory);
    private:
        DataAccess::IProductRepository *productRepository;
        DataAccess::IUserRepository *userRepository;
        DataAccess::ICouponRepository *couponRepository;
        DataAccess::IRepositoryFactory *repositoryFactory;
    };
}

#endif //E_COMMERCE_STORAGESERVICE_H
