//
// Created by chi on 24/04/30.
//

#include <stdexcept>
#include "SessionManager.h"
#include "DataAccess/CartOrderRepository.h"
#include "StorageService.h"
#include "PurchaseService.h"

namespace Service {
    SessionManager::SessionManager() : currentUser(), cartOrderRepository(nullptr), purchaseService(nullptr) {}

    // 登录时初始化购物车订单仓储和购买服务
    void SessionManager::loginUser(const DataType::NormalUser &user) {
        currentUser = user;
        delete cartOrderRepository;
        delete purchaseService;
        StorageService *storageService = StorageService::getInstance();
        cartOrderRepository = storageService->getRepositoryFactory().getCartOrderRepository(
                storageService->getProductRepository(), user.getUsername());
        purchaseService = new PurchaseService(
                *cartOrderRepository,
                storageService->getCouponRepository()
        );
    }

    // 注销时删除购物车订单仓储和购买服务
    void SessionManager::logoutUser() {
        currentUser = std::nullopt;
        delete cartOrderRepository;
        cartOrderRepository = nullptr;
        delete purchaseService;
        purchaseService = nullptr;
    }

    bool SessionManager::getLoginStatus() const {
        return currentUser.has_value();
    }

    std::optional<DataType::NormalUser> SessionManager::getCurrentUser() const {
        return currentUser;
    }

    // 获取购物车订单仓储，如果用户未登录则抛出异常
    DataAccess::ICartOrderRepository &SessionManager::getCartOrderRepository() const {
        if (!cartOrderRepository) {
            throw std::runtime_error("User not logged in");
        }
        return *cartOrderRepository;
    }

    SessionManager::~SessionManager() {
        delete cartOrderRepository;
        delete purchaseService;
    }

    // 获取购买服务，如果用户未登录则抛出异常
    PurchaseService &SessionManager::getPurchaseService() const {
        if (!purchaseService) {
            throw std::runtime_error("User not logged in");
        }
        return *purchaseService;
    }
}