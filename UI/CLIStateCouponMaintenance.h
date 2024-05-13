//
// Created by chi on 24/05/13.
//

#ifndef E_COMMERCE_CLISTATECOUPONMAINTENANCE_H
#define E_COMMERCE_CLISTATECOUPONMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {

    class CLIStateCouponMaintenance : public ICLIState {
    public:
        explicit CLIStateCouponMaintenance(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;
    private:
        void displayCouponList();

        void displayUserCouponList(const std::string &username);

        CLIUserInterface &userInterface;
    };

} // UI

#endif //E_COMMERCE_CLISTATECOUPONMAINTENANCE_H
