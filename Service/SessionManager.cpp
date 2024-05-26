//
// Created by chi on 24/04/30.
//

#include <stdexcept>
#include "SessionManager.h"
#include "DataAccess/CartOrderRepository.h"
#include "StorageService.h"
#include "PurchaseService.h"

namespace Service {
    using DataAccess::ICartOrderRepository;
    using DataAccess::CartOrderRepository;
    using DataType::NormalUser;

    SessionManager::SessionManager() : currentUser(), cartOrderRepository(nullptr), purchaseService(nullptr) {}


    void SessionManager::loginUser(const NormalUser &user) {
        currentUser = user;
        delete cartOrderRepository;
        delete purchaseService;
        StorageService *storageService = StorageService::getInstance();
        cartOrderRepository = storageService->getRepositoryFactory().getCartOrderRepository(
                storageService->getProductRepository(), user.getUsername());
        purchaseService = new PurchaseService(*cartOrderRepository,
                                              storageService->getCouponRepository());
    }

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

    std::optional<NormalUser> SessionManager::getCurrentUser() const {
        return currentUser;
    }

    ICartOrderRepository &SessionManager::getCartOrderRepository() const {
        if (!cartOrderRepository) {
            throw std::runtime_error("User not logged in");
        }
        return *cartOrderRepository;
    }

    SessionManager::~SessionManager() {
        delete cartOrderRepository;
        delete purchaseService;
    }

    PurchaseService &SessionManager::getPurchaseService() const {
        if (!purchaseService) {
            throw std::runtime_error("User not logged in");
        }
        return *purchaseService;
    }
}