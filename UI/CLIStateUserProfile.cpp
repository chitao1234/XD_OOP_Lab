//
// Created by chi on 24/04/28.
//

#include <iostream>
#include "CLIStateUserProfile.h"
#include "Service/SessionManager.h"
#include "Service/StorageService.h"
#include "Util/ErrorCheckingInputStream.h"

namespace UI {
    using Service::SessionManager;
    using Service::StorageService;
    using DataAccess::IUserRepository;
    using DataType::NormalUser;

    void CLIStateUserProfile::displayMenu() {
        std::cout << "1. View profile\n"
                     "2. Edit profile\n"
                     "3. Change password\n"
                     "4. Go back\n"
                     "Enter your choice: ";
    }

    void CLIStateUserProfile::handleUserInput() {
        int choice;
        Util::cinWrapper >> choice;
        switch (choice) {
            case 1:
                std::cout << "User name: " << user.getUsername() << std::endl;
                std::cout << "Email: " << user.getEmail() << std::endl;
                break;
            case 2: {
                IUserRepository &userRepository = StorageService::getInstance()->getUserRepository();
                std::string email;
                std::cout << "Editing profile...\n"
                             "Enter new email: ";
                Util::cinWrapper >> email;
                user.setEmail(email);
                userRepository.updateUser(user);
                SessionManager::getInstance()->loginUser(user);
                break;
            }
            case 3: {
                IUserRepository &userRepository = StorageService::getInstance()->getUserRepository();
                std::string oldPassword, newPassword, confirmPassword;
                std::cout << "Changing password...\n"
                             "Old password: ";
                Util::cinWrapper >> oldPassword;
                std::cout << "New password: ";
                Util::cinWrapper >> newPassword;
                std::cout << "Confirm new password: ";
                Util::cinWrapper >> confirmPassword;
                if (newPassword != confirmPassword) {
                    std::cout << "Passwords do not match.\n";
                    break;
                }
                if (userRepository.changePassword(user, oldPassword, newPassword)) {
                    std::cout << "Password changed.\n";
                } else {
                    std::cout << "Old password is incorrect.\n";
                    break;
                }
                user = userRepository.login(user.getUsername(), newPassword).value();
                SessionManager::getInstance()->loginUser(user);
                break;
            }
            case 4:
                std::cout << "Going back..." << std::endl;
                userInterface.popState();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        std::cout << std::endl;

    }

    CLIStateUserProfile::CLIStateUserProfile(CLIUserInterface &userInterface, NormalUser user) : userInterface(
            userInterface), user(std::move(user)) {
    }
}
