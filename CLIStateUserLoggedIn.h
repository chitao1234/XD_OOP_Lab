//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_CLISTATEUSERLOGGEDIN_H
#define E_COMMERCE_CLISTATEUSERLOGGEDIN_H


#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "User.h"

class CLIStateUserLoggedIn : public ICLIState {
public:
    CLIStateUserLoggedIn(CLIUserInterface &userInterface, NormalUser &user);

    void displayMenu() override;

    void handleUserInput() override;

private:
    CLIUserInterface &userInterface;
    NormalUser user;
};


#endif //E_COMMERCE_CLISTATEUSERLOGGEDIN_H
