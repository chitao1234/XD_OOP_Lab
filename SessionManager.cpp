//
// Created by chi on 24/04/30.
//

#include <stdexcept>
#include "SessionManager.h"
#include "ShoppingCartRepository.h"
#include "StorageService.h"

SessionManager::SessionManager() : currentUser(), shoppingCartRepository(nullptr) {}


void SessionManager::loginUser(const NormalUser &user) {
    currentUser = user;
    shoppingCartRepository = new ShoppingCartRepository(StorageService::getInstance()->getProductRepository(),
                                                        user.getUsername());
}

void SessionManager::logoutUser() {
    currentUser = std::nullopt;
    delete shoppingCartRepository;
    shoppingCartRepository = nullptr;
}

bool SessionManager::getLoginStatus() const {
    return currentUser.has_value();
}

std::optional<NormalUser> SessionManager::getCurrentUser() const {
    return currentUser;
}

IShoppingCartRepository &SessionManager::getShoppingCartRepository() const {
    if (!shoppingCartRepository) {
        throw std::runtime_error("User not logged in");
    }
    return *shoppingCartRepository;
}

SessionManager::~SessionManager() {
    delete shoppingCartRepository;
}
