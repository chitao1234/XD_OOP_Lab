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


namespace Service {
    class StorageService : public SingletonTemplate<StorageService> {
    public:
        [[nodiscard]] DataAccess::IProductRepository &getProductRepository() const;

        [[nodiscard]] DataAccess::IUserRepository &getUserRepository() const;

        [[nodiscard]] DataAccess::ICouponRepository &getCouponRepository() const;

        [[nodiscard]] DataAccess::IDaoFactory &getDaoFactory() const;

        void setProductRepository(DataAccess::IProductRepository &productRepository);

        void setUserRepository(DataAccess::IUserRepository &userRepository);

        void setCouponRepository(DataAccess::ICouponRepository &couponRepository);

        void setDaoFactory(DataAccess::IDaoFactory &daoFactory);
    private:
        DataAccess::IProductRepository *productRepository;
        DataAccess::IUserRepository *userRepository;
        DataAccess::ICouponRepository *couponRepository;
        DataAccess::IDaoFactory *daoFactory;
    };
}

#endif //E_COMMERCE_STORAGESERVICE_H
