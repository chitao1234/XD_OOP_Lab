//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_STORAGESERVICE_H
#define E_COMMERCE_STORAGESERVICE_H

#include <optional>
#include "SingletonTemplate.h"
#include "../DataAccess/IProductRepository.h"
#include "../DataAccess/IUserRepository.h"


namespace Service {
    class StorageService : public SingletonTemplate<StorageService> {
    public:
        [[nodiscard]] DataAccess::IProductRepository &getProductRepository() const;

        [[nodiscard]] DataAccess::IUserRepository &getUserRepository() const;

        void setProductRepository(DataAccess::IProductRepository &productRepository);

        void setUserRepository(DataAccess::IUserRepository &userRepository);

    private:
        DataAccess::IProductRepository *productRepository;
        DataAccess::IUserRepository *userRepository;
    };
}

#endif //E_COMMERCE_STORAGESERVICE_H
