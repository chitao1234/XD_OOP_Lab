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


namespace Service {
    class StorageService : public SingletonTemplate<StorageService> {
    public:
        [[nodiscard]] DataAccess::IProductRepository &getProductRepository() const;

        [[nodiscard]] DataAccess::IUserRepository &getUserRepository() const;

        [[nodiscard]] DataAccess::ICouponRepository &getCouponRepository() const;

        void setProductRepository(DataAccess::IProductRepository &productRepository);

        void setUserRepository(DataAccess::IUserRepository &userRepository);

        void setCouponRepository(DataAccess::ICouponRepository &couponRepository);
    private:
        DataAccess::IProductRepository *productRepository;
        DataAccess::IUserRepository *userRepository;
        DataAccess::ICouponRepository *couponRepository;
    };
}

#endif //E_COMMERCE_STORAGESERVICE_H
