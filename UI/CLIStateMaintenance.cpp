//
// Created by chi on 24/05/05.
//

#include <iostream>
#include "CLIStateMaintenance.h"
#include "CLIStateProductMaintenance.h"
#include "CLIStateUserMaintenance.h"
#include "CLIStateCouponMaintenance.h"
#include "Util/ErrorCheckingInputStream.h"

namespace UI {
    CLIStateMaintenance::CLIStateMaintenance(CLIUserInterface &userInterface) : userInterface(userInterface) {
    }

    void CLIStateMaintenance::displayMenu() {
        std::cout << "Maintenance" << std::endl;
        std::cout << "1. Product Maintenance\n"
                     "2. User Maintenance\n"
                     "3. Coupon Maintenance\n"
                     "4. Back\n"
                     "Enter your choice: ";
    }

    void CLIStateMaintenance::handleUserInput() {
        int choice;
        Util::cinWrapper >> choice;
        switch (choice) {
            case 1: {
                userInterface.pushState(new CLIStateProductMaintenance(userInterface));
                break;
            }
            case 2: {
                userInterface.pushState(new CLIStateUserMaintenance(userInterface));
                break;
            }
            case 3: {
                userInterface.pushState(new CLIStateCouponMaintenance(userInterface));
                break;
            }
            case 4: {
                userInterface.popState();
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }
}
