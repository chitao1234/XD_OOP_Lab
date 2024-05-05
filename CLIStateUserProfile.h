//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_CLISTATEUSERPROFILE_H
#define E_COMMERCE_CLISTATEUSERPROFILE_H


#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "NormalUser.h"

class CLIStateUserProfile : public ICLIState {
public:
    CLIStateUserProfile(CLIUserInterface &userInterface, NormalUser user);

    void displayMenu() override;

    void handleUserInput() override;

private:
    CLIUserInterface &userInterface;
    NormalUser user;
};


#endif //E_COMMERCE_CLISTATEUSERPROFILE_H
