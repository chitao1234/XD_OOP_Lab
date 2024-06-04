#ifndef E_COMMERCE_CLISTATEMAINMENU_H
#define E_COMMERCE_CLISTATEMAINMENU_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {
    // 主菜单界面类，用于实现登录，浏览商品，注册等功能
    class CLIStateMainMenu : public ICLIState {
    public:
        explicit CLIStateMainMenu(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
    };
}

#endif //E_COMMERCE_CLISTATEMAINMENU_H
