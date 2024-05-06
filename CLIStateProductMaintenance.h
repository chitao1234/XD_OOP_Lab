//
// Created by chi on 24/05/01.
//

#ifndef E_COMMERCE_CLISTATEPRODUCTMAINTENANCE_H
#define E_COMMERCE_CLISTATEPRODUCTMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "ProductDisplay.h"

class CLIStateProductMaintenance : public ICLIState{
public:
    explicit CLIStateProductMaintenance(CLIUserInterface &userInterface);

    void displayMenu() override;

    void handleUserInput() override;
private:
    CLIUserInterface &userInterface;
    ProductDisplay productDisplay;
};


#endif //E_COMMERCE_CLISTATEPRODUCTMAINTENANCE_H
