//
// Created by chi on 24/05/05.
//

#include <iostream>
#include "CLIStateUserMaintenance.h"
#include "Service/StorageService.h"
#include "Util/ErrorCheckingInputStream.h"

namespace UI {
    using DataAccess::IUserRepository;
    using Service::StorageService;
    using DataType::NormalUser;

    CLIStateUserMaintenance::CLIStateUserMaintenance(CLIUserInterface &userInterface) : userInterface(userInterface) {
    }

    void CLIStateUserMaintenance::displayMenu() {
        std::cout << "User Maintenance" << std::endl;
        std::cout << "1. List users\n"
                     "2. Add user\n"
                     "3. Update user\n"
                     "4. Delete user\n"
                     "5. Back\n"
                     "Enter your choice: ";
    }

    void CLIStateUserMaintenance::handleUserInput() {
        int choice;
        Util::cinWrapper >> choice;
        switch (choice) {
            case 1: {
                listUsers();
                break;
            }
            case 2: {
                IUserRepository &userRepository = StorageService::getInstance()->getUserRepository();
                std::string username, password, email;
                std::cout << "Enter username: ";
                Util::cinWrapper >> username;
                std::cout << "Enter password: ";
                Util::cinWrapper >> password;
                std::cout << "Enter email: ";
                Util::cinWrapper >> email;
                NormalUser user = NormalUser(username, password, email);
                if (userRepository.registerUser(user)) {
                    std::cout << "User added" << std::endl;
                } else {
                    std::cout << "Username already exists" << std::endl;
                }
                break;
            }
            case 3: {
                listUsers();
                IUserRepository &userRepository = StorageService::getInstance()->getUserRepository();
                std::optional<NormalUser> user = readUser();
                if (!user.has_value()) {
                    std::cout << "User not found" << std::endl;
                    break;
                }
                std::cout << "User Info:\n";
                std::cout << user->getUsername() << " " << user->getEmail() << std::endl;
                std::string newUsername, newPassword, newEmail;
                std::cout << "Enter new username: ";
                Util::cinWrapper >> newUsername;
                std::cout << "Enter new password: ";
                Util::cinWrapper >> newPassword;
                std::cout << "Enter new email: ";
                Util::cinWrapper >> newEmail;
                NormalUser newUser = {newUsername, newPassword, newEmail};
                userRepository.replaceUser(user.value(), newUser);
                std::cout << "User updated" << std::endl;
                break;
            }
            case 4: {
                listUsers();
                IUserRepository &userRepository = StorageService::getInstance()->getUserRepository();
                std::optional<NormalUser> user = readUser();
                if (!user.has_value()) {
                    std::cout << "User not found" << std::endl;
                    break;
                }
                userRepository.deleteUser(user->getUsername());
                std::cout << "User deleted" << std::endl;
                break;
            }
            case 5: {
                userInterface.popState();
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }

    void CLIStateUserMaintenance::listUsers() {
        IUserRepository &userRepository = StorageService::getInstance()->getUserRepository();
        std::vector<NormalUser> users = userRepository.listUsers();
        std::cout << "Users:\n";
        for (const NormalUser &user: users) {
            std::cout << user.getUsername() << " " << user.getEmail() << std::endl;
        }
        std::cout << std::endl;
    }

    std::optional<NormalUser> CLIStateUserMaintenance::readUser() {
        std::string username;
        std::cout << "Enter username: ";
        Util::cinWrapper >> username;
        IUserRepository &userRepository = StorageService::getInstance()->getUserRepository();
        std::optional<NormalUser> user = userRepository.findUserByUsername(username);
        return user;
    }
}

