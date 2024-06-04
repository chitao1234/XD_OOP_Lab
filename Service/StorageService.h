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
    // 存储服务类，用于提供数据仓储，采用单例模式，保证数据仓储的唯一性
    // 通过数据仓储工厂进行数据仓储的初始化
    class StorageService : public SingletonTemplate<StorageService> {
    public:
        // 使用友元类，以便单例模板访问私有构造函数
        friend class SingletonTemplate<StorageService>;

        StorageService() = default;

        ~StorageService() = default;

        [[nodiscard]] DataAccess::IProductRepository &getProductRepository();

        [[nodiscard]] DataAccess::IUserRepository &getUserRepository();

        [[nodiscard]] DataAccess::ICouponRepository &getCouponRepository();

        [[nodiscard]] DataAccess::IRepositoryFactory &getRepositoryFactory() const;

        // 设置数据仓储工厂，进行数据仓储的初始化
        void setRepositoryFactory(DataAccess::IRepositoryFactory *repositoryFactory);

    private:
        DataAccess::IProductRepository *productRepository;
        DataAccess::IUserRepository *userRepository;
        DataAccess::ICouponRepository *couponRepository;
        DataAccess::IRepositoryFactory *repositoryFactory;
    };
}

#endif //E_COMMERCE_STORAGESERVICE_H
