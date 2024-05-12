#ifndef E_COMMERCE_CLISTATEMAINMENU_H
#define E_COMMERCE_CLISTATEMAINMENU_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {
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
