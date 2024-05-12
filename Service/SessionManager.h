//
// Created by chi on 24/04/30.
//

#ifndef E_COMMERCE_SESSIONMANAGER_H
#define E_COMMERCE_SESSIONMANAGER_H


#include <optional>
#include "../DataType/NormalUser.h"
#include "../DataAccess/IShoppingCartRepository.h"
#include "SingletonTemplate.h"

namespace Service {

    class SessionManager : public SingletonTemplate<SessionManager> {
    private:
        friend class SingletonTemplate<SessionManager>;

        std::optional <DataType::NormalUser> currentUser;
        DataAccess::IShoppingCartRepository *shoppingCartRepository;

        SessionManager();

        ~SessionManager();

    public:

        void loginUser(const DataType::NormalUser &user);

        void logoutUser();

        [[nodiscard]] bool getLoginStatus() const;

        [[nodiscard]] std::optional <DataType::NormalUser> getCurrentUser() const;

        [[nodiscard]] DataAccess::IShoppingCartRepository &getShoppingCartRepository() const;
    };
}

#endif //E_COMMERCE_SESSIONMANAGER_H
