#include "CLIStateMainMenu.h"

#include <iostream>

#include "NormalUser.h"
#include "CLIStateUserLoggedIn.h"
#include "CLIStateProductList.h"
#include "CLIStateMaintenance.h"
#include "SessionManager.h"

void CLIStateMainMenu::displayMenu() {
    std::cout << "1. Login\n"
                 "2. Register\n"
                 "3. View products\n"
                 "4. Exit\n"
                 "Enter your choice: ";
}

void CLIStateMainMenu::handleUserInput() {
    int choice;
    std::cin >> choice;
    IUserRepository &userRepository = userInterface.getUserRepository();
    switch (choice) {
        case 1: {
            std::string username, password;
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;
            if (userRepository.loginAsAdmin(username, password)) {
                std::cout << "Welcome, admin.\n";
                userInterface.pushState(new CLIStateMaintenance(userInterface));
                break;
            }
            std::optional<NormalUser> user = userRepository.login(username, password);
            if (user.has_value()) {
                std::cout << "Login successful.\n";
                SessionManager::getInstance()->loginUser(user.value());
                userInterface.pushState(new CLIStateUserLoggedIn(userInterface));
            } else {
                std::cout << "Login failed.\n";
            }
            break;
        }
        case 2: {
            std::string username, password, email;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            std::cout << "Enter email: ";
            std::cin >> email;
            NormalUser user = NormalUser(username, password, email);
            if (userRepository.registerUser(user)) {
                std::cout << "Registration successful.\n";
            } else {
                std::cout << "Username already exists.\n";
            }
            break;
        }
        case 3: {
            IProductRepository &productRepository = userInterface.getProductRepository();
            std::vector<Product> products = productRepository.listProducts();
            std::cout << "View products...\n";
            userInterface.pushState(new CLIStateProductList(userInterface, products));
            break;
        }
        case 4:
            std::cout << "Exiting...\n";
            userInterface.popState();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }

    std::cout <<
              std::endl;
}

CLIStateMainMenu::CLIStateMainMenu(CLIUserInterface &userInterface)
        : userInterface(userInterface) {
}
