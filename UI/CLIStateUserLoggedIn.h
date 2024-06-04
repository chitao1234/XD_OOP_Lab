//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_CLISTATEUSERLOGGEDIN_H
#define E_COMMERCE_CLISTATEUSERLOGGEDIN_H


#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "DataType/User.h"

namespace UI {
    // 用户登录后的界面类，用于显示用户登录后的操作菜单，包括查看商品列表、查看购物车和订单，信息管理
    class CLIStateUserLoggedIn : public ICLIState {
    public:
        explicit CLIStateUserLoggedIn(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
    };
}


#endif //E_COMMERCE_CLISTATEUSERLOGGEDIN_H
