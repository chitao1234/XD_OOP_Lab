//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_CLISTATEORDERHISTORY_H
#define E_COMMERCE_CLISTATEORDERHISTORY_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {

    class CLIStateOrderHistory : public ICLIState {
    public:
        explicit CLIStateOrderHistory(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        std::tm start, end;
        std::string category;
    };

} // UI

#endif //E_COMMERCE_CLISTATEORDERHISTORY_H
