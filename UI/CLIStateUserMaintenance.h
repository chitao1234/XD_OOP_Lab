//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_CLISTATEUSERMAINTENANCE_H
#define E_COMMERCE_CLISTATEUSERMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {
    // 用户信息维护界面类，用于添加、修改、删除用户
    class CLIStateUserMaintenance : public ICLIState {
    public:
        explicit CLIStateUserMaintenance(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        // 列出所有用户
        void listUsers();

        // 用于选择用户
        std::optional<DataType::NormalUser> readUser();

        CLIUserInterface &userInterface;
    };
}


#endif //E_COMMERCE_CLISTATEUSERMAINTENANCE_H
