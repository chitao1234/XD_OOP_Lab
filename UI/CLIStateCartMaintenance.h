//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_CLISTATECARTMAINTENANCE_H
#define E_COMMERCE_CLISTATECARTMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {
    class CLIStateCartMaintenance : public ICLIState {
    public:
        explicit CLIStateCartMaintenance(CLIUserInterface &userInterface, std::pair<DataType::FullProduct, long> product);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        std::pair<DataType::FullProduct, long> product;
    };
}

#endif //E_COMMERCE_CLISTATECARTMAINTENANCE_H
