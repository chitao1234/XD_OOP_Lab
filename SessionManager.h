//
// Created by chi on 24/04/30.
//

#ifndef E_COMMERCE_SESSIONMANAGER_H
#define E_COMMERCE_SESSIONMANAGER_H


#include <optional>
#include "NormalUser.h"
#include "IShoppingCartRepository.h"
#include "SingletonTemplate.h"

class SessionManager : public SingletonTemplate<SessionManager> {
private:
    friend class SingletonTemplate<SessionManager>;

    std::optional<NormalUser> currentUser;
    IShoppingCartRepository *shoppingCartRepository;

    SessionManager();

    ~SessionManager();

public:

    void loginUser(const NormalUser &user);

    void logoutUser();

    [[nodiscard]] bool getLoginStatus() const;

    [[nodiscard]] std::optional<NormalUser> getCurrentUser() const;

    [[nodiscard]] IShoppingCartRepository &getShoppingCartRepository() const;
};


#endif //E_COMMERCE_SESSIONMANAGER_H
