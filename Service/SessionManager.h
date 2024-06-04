//
// Created by chi on 24/04/30.
//

#ifndef E_COMMERCE_SESSIONMANAGER_H
#define E_COMMERCE_SESSIONMANAGER_H


#include <optional>
#include "DataType/NormalUser.h"
#include "DataAccess/ICartOrderRepository.h"
#include "SingletonTemplate.h"
#include "PurchaseService.h"

namespace Service {
    // 会话管理类，用于管理用户的登录状态，同时提供购物车和购买服务
    class SessionManager : public SingletonTemplate<SessionManager> {
    private:
        // 使用友元类，以便单例模板访问私有构造函数
        friend class SingletonTemplate<SessionManager>;

        std::optional <DataType::NormalUser> currentUser;
        DataAccess::ICartOrderRepository *cartOrderRepository;
        PurchaseService *purchaseService;

        // 使用单例模式，禁止外部创建对象
        SessionManager();

        ~SessionManager();

    public:
        // 登录用户
        void loginUser(const DataType::NormalUser &user);

        // 注销用户
        void logoutUser();

        // 获取登录状态
        [[nodiscard]] bool getLoginStatus() const;

        // 获取当前用户信息，仅限普通用户，如果没有用户登录，返回空
        [[nodiscard]] std::optional <DataType::NormalUser> getCurrentUser() const;

        // 获取购物车订单仓储
        [[nodiscard]] DataAccess::ICartOrderRepository &getCartOrderRepository() const;

        // 获取购买服务
        [[nodiscard]] PurchaseService &getPurchaseService() const;
    };
}

#endif //E_COMMERCE_SESSIONMANAGER_H
