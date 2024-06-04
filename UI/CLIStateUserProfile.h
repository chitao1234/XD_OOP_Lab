//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_CLISTATEUSERPROFILE_H
#define E_COMMERCE_CLISTATEUSERPROFILE_H


#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "DataType/NormalUser.h"

namespace UI {
    // 用户信息界面类，用于显示用户信息，和更改用户信息，包括更改密码、邮箱等
    class CLIStateUserProfile : public ICLIState {
    public:
        CLIStateUserProfile(CLIUserInterface &userInterface, DataType::NormalUser user);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        DataType::NormalUser user;
    };
}


#endif //E_COMMERCE_CLISTATEUSERPROFILE_H
