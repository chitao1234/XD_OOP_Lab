//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_CLISTATEPRODUCTLIST_H
#define E_COMMERCE_CLISTATEPRODUCTLIST_H

#include <vector>
#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "DataType/Product.h"
#include "ProductDisplay.h"

namespace UI {
    class CLIStateProductList : public ICLIState {
    public:
        CLIStateProductList(CLIUserInterface &userInterface, const std::vector<DataType::Product> &products);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        ProductDisplay productDisplay;
    };
}


#endif //E_COMMERCE_CLISTATEPRODUCTLIST_H
