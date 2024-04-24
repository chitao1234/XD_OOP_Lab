#include "CLIStateMainMenu.h"
#include <iostream>

void CLIStateMainMenu::displayMenu() {
    std::cout << "1. Login\n2. Register\n3. Exit\nEnter your choice: ";
}

bool CLIStateMainMenu::handleUserInput() {
    bool exit = false;
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
            if (userRepository.login(username, password)) {
                std::cout << "Login successful.\n";
            } else {
                std::cout << "Login failed.\n";
            }
            break;
        }
        case 2: {
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            User user = User(username, password);
            if (userRepository.registerUser(user)) {
                std::cout << "Registration successful.\n";
            } else {
                std::cout << "Username already exists.\n";
            }
            break;
        }
        case 3:
            std::cout << "Exiting...\n";
            exit = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
    std::cout << std::endl;
    return exit;
}

CLIStateMainMenu::CLIStateMainMenu(CLIUserInterface &userInterface) : userInterface(userInterface) {}
