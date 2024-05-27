//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_CLISTATECART_H
#define E_COMMERCE_CLISTATECART_H

#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "ProductDisplay.h"
#include "DataType/Coupon.h"

namespace UI {
    class CLIStateCart : public ICLIState {
    public:
        explicit CLIStateCart(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        ProductDisplay productDisplay;
        std::vector<std::pair<DataType::FullProduct, long>> selected;

        std::optional<DataType::Coupon> displayCoupons(bool select);
    };
}


#endif //E_COMMERCE_CLISTATECART_H
