//
// Created by chi on 24/04/28.
//

#include <iostream>
#include "CLIStateUserLoggedIn.h"
#include "CLIStateMainMenu.h"
#include "CLIStateUserProfile.h"
#include "CLIStateProductList.h"
#include "Service/SessionManager.h"
#include "Service/StorageService.h"
#include "Util/ErrorCheckingInputStream.h"
#include "CLIStateCart.h"

namespace UI {
    using Service::SessionManager;
    using Service::StorageService;

    void CLIStateUserLoggedIn::displayMenu() {
        std::cout << "1. View products\n"
                     "2. View cart\n"
                     "3. View user page\n"
                     "4. Logout\n"
                     "Enter your choice: ";
    }

    void CLIStateUserLoggedIn::handleUserInput() {
        int choice;
        Util::cinWrapper >> choice;
        switch (choice) {
            case 1:
                userInterface.pushState(new CLIStateProductList(
                        userInterface,
                        StorageService::getInstance()
                                ->getProductRepository().listProducts()));
                break;
            case 2:
                userInterface.pushState(new CLIStateCart(userInterface));
                break;
            case 3:
                userInterface.pushState(new CLIStateUserProfile(userInterface,
                                                                SessionManager::getInstance()
                                                                        ->getCurrentUser().value()));
                break;
            case 4:
                std::cout << "Logging out..." << std::endl;
                SessionManager::getInstance()->logoutUser();
                userInterface.popState();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        std::cout << std::endl;
    }

    CLIStateUserLoggedIn::CLIStateUserLoggedIn(CLIUserInterface &userInterface) : userInterface(
            userInterface) {
    }
}
