//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_CLISTATECARTMAINTENANCE_H
#define E_COMMERCE_CLISTATECARTMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {
    // 购物车维护界面类，用于实现购物车商品维护功能
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
