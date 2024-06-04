//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_CLISTATEMAINTENANCE_H
#define E_COMMERCE_CLISTATEMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {
    // 维护界面类，用于实现产品、用户和优惠券的维护功能
    class CLIStateMaintenance : public ICLIState {
    public:
        explicit CLIStateMaintenance(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
    };
}


#endif //E_COMMERCE_CLISTATEMAINTENANCE_H
