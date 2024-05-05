//
// Created by chi on 24/04/30.
//

#ifndef E_COMMERCE_SESSIONMANAGER_H
#define E_COMMERCE_SESSIONMANAGER_H


#include <optional>
#include "NormalUser.h"

class SessionManager {
private:
    static SessionManager *instance;
    std::optional<NormalUser> currentUser;

    SessionManager();

public:
    static SessionManager *getInstance();

    void loginUser(const NormalUser &user);

    void logoutUser();

    [[nodiscard]] bool getLoginStatus() const;

    [[nodiscard]] std::optional<NormalUser> getCurrentUser() const;
};


#endif //E_COMMERCE_SESSIONMANAGER_H
