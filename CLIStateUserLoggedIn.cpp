//
// Created by chi on 24/04/28.
//

#include <iostream>
#include "CLIStateUserLoggedIn.h"
#include "CLIStateMainMenu.h"

void CLIStateUserLoggedIn::displayMenu() {
    std::cout << "1. View products\n"
                 "2. View cart\n"
                 "3. View profile\n"
                 "4. Logout\n"
                 "Enter your choice: ";
}

bool CLIStateUserLoggedIn::handleUserInput() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Viewing products..." << std::endl;
            break;
        case 2:
            std::cout << "Viewing cart..." << std::endl;
            break;
        case 3:
            std::cout << "Viewing profile..." << std::endl;
            break;
        case 4:
            std::cout << "Logging out..." << std::endl;
            userInterface.setState(new CLIStateMainMenu(userInterface));
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    return false;
}

CLIStateUserLoggedIn::CLIStateUserLoggedIn(CLIUserInterface &userInterface, NormalUser &user) : userInterface(
        userInterface), user(user) {
}
