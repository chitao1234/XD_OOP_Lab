//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_CLISTATEUSERLOGGEDIN_H
#define E_COMMERCE_CLISTATEUSERLOGGEDIN_H


#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "DataType/User.h"

namespace UI {
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
