//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_CLISTATECART_H
#define E_COMMERCE_CLISTATECART_H

#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "ProductDisplay.h"

class CLIStateCart : public ICLIState {
public:
    CLIStateCart(CLIUserInterface &userInterface);

    void displayMenu() override;

    void handleUserInput() override;

private:
    CLIUserInterface &userInterface;
    ProductDisplay productDisplay;
    std::vector<std::pair<Product, long>> selected;
};


#endif //E_COMMERCE_CLISTATECART_H
