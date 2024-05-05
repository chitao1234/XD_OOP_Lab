//
// Created by chi on 24/04/28.
//

#include <iostream>
#include "CLIStateUserLoggedIn.h"
#include "CLIStateMainMenu.h"
#include "CLIStateUserProfile.h"
#include "CLIStateProductList.h"
#include "SessionManager.h"

void CLIStateUserLoggedIn::displayMenu() {
    std::cout << "1. View products\n"
                 "2. View cart\n"
                 "3. View user page\n"
                 "4. Logout\n"
                 "Enter your choice: ";
}

void CLIStateUserLoggedIn::handleUserInput() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            // TODO: search
            userInterface.pushState(
                    new CLIStateProductList(userInterface, userInterface.getProductRepository().listProducts()));
            break;
        case 2:
            // TODO: cart
            std::cout << "Viewing cart..." << std::endl;
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
