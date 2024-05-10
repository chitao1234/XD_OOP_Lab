//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_STORAGESERVICE_H
#define E_COMMERCE_STORAGESERVICE_H

#include <optional>
#include "SingletonTemplate.h"
#include "../DataAccess/IProductRepository.h"
#include "../DataAccess/IUserRepository.h"


class StorageService : public SingletonTemplate<StorageService> {
public:
    [[nodiscard]] IProductRepository &getProductRepository() const;

    [[nodiscard]] IUserRepository &getUserRepository() const;

    void setProductRepository(IProductRepository &productRepository);

    void setUserRepository(IUserRepository &userRepository);

private:
    IProductRepository *productRepository;
    IUserRepository *userRepository;
};

#endif //E_COMMERCE_STORAGESERVICE_H
