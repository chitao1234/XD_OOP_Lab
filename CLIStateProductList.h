//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_CLISTATEPRODUCTLIST_H
#define E_COMMERCE_CLISTATEPRODUCTLIST_H

#include <vector>
#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "Product.h"

class CLIStateProductList : public ICLIState {
public:
    CLIStateProductList(CLIUserInterface &userInterface, const std::vector<Product> &products);

    void displayMenu() override;

    void handleUserInput() override;

private:
    CLIUserInterface &userInterface;
    std::vector<Product> products;
};


#endif //E_COMMERCE_CLISTATEPRODUCTLIST_H
