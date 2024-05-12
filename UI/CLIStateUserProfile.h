//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_CLISTATEUSERPROFILE_H
#define E_COMMERCE_CLISTATEUSERPROFILE_H


#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "DataType/NormalUser.h"

namespace UI {
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
