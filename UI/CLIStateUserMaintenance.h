//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_CLISTATEUSERMAINTENANCE_H
#define E_COMMERCE_CLISTATEUSERMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {
    class CLIStateUserMaintenance : public ICLIState {
    public:
        explicit CLIStateUserMaintenance(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        void listUsers();

        std::optional<DataType::NormalUser> readUser();

        CLIUserInterface &userInterface;
    };
}


#endif //E_COMMERCE_CLISTATEUSERMAINTENANCE_H
