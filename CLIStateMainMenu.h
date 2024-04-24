#ifndef E_COMMERCE_CLISTATEMAINMENU_H
#define E_COMMERCE_CLISTATEMAINMENU_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

class CLIStateMainMenu : public ICLIState {
public:
    CLIStateMainMenu(CLIUserInterface &userInterface);

    void displayMenu();
    bool handleUserInput();
private:
    CLIUserInterface &userInterface;
};


#endif //E_COMMERCE_CLISTATEMAINMENU_H
