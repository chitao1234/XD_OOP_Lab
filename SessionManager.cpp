//
// Created by chi on 24/04/30.
//

#include "SessionManager.h"

SessionManager::SessionManager() : currentUser() {}

SessionManager *SessionManager::getInstance() {
    if (!instance)
        instance = new SessionManager();
    return instance;
}

void SessionManager::loginUser(const NormalUser &user) {
    currentUser = user;
}

void SessionManager::logoutUser() {
    currentUser = std::nullopt;
}

bool SessionManager::getLoginStatus() const {
    return currentUser.has_value();
}

std::optional<NormalUser> SessionManager::getCurrentUser() const {
    return currentUser;
}

SessionManager *SessionManager::instance = nullptr;