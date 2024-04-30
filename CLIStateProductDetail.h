//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_CLISTATEPRODUCTDETAIL_H
#define E_COMMERCE_CLISTATEPRODUCTDETAIL_H

#include "ICLIState.h"
#include "Product.h"
#include "CLIUserInterface.h"

class CLIStateProductDetail : public ICLIState {
public:
    CLIStateProductDetail(CLIUserInterface &userInterface, Product product);

    void displayMenu() override;

    void handleUserInput() override;
private:
    CLIUserInterface &userInterface;
    Product product;
};


#endif //E_COMMERCE_CLISTATEPRODUCTDETAIL_H