#include "CLIStateMainMenu.h"

#include <iostream>

#include "DataType/NormalUser.h"
#include "CLIStateUserLoggedIn.h"
#include "CLIStateProductList.h"
#include "CLIStateMaintenance.h"
#include "Service/SessionManager.h"
#include "Service/StorageService.h"
#include "Util/ErrorCheckingInputStream.h"

namespace UI {
    using Service::SessionManager;
    using Service::StorageService;

    void CLIStateMainMenu::displayMenu() {
        std::cout << "1. Login\n"
                     "2. Register\n"
                     "3. View products\n"
                     "4. Exit\n"
                     "Enter your choice: ";
    }

    void CLIStateMainMenu::handleUserInput() {
        int choice;
        Util::cinWrapper >> choice;
        DataAccess::IUserRepository &userRepository = StorageService::getInstance()->getUserRepository();
        switch (choice) {
            case 1: {
                std::string username, password;
                std::cout << "Username: ";
                Util::cinWrapper >> username;
                std::cout << "Password: ";
                Util::cinWrapper >> password;

                // 使用用户仓储登录用户，同时检查是否为管理员
                if (userRepository.loginAsAdmin(username, password)) {
                    std::cout << "Welcome, admin.\n";
                    userInterface.pushState(new CLIStateMaintenance(userInterface));
                    break;
                }
                std::optional<DataType::NormalUser> user = userRepository.login(username, password);
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
                Util::cinWrapper >> username;
                std::cout << "Enter password: ";
                Util::cinWrapper >> password;
                std::cout << "Enter email: ";
                Util::cinWrapper >> email;
                DataType::NormalUser user = DataType::NormalUser(username, password, email);
                if (userRepository.registerUser(user)) {
                    std::cout << "Registration successful.\n";
                } else {
                    std::cout << "Username already exists.\n";
                }
                break;
            }
            case 3: {
                DataAccess::IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
                std::vector<DataType::FullProduct> products = productRepository.listProducts();
                std::cout << "View products...\n";
                // 跳转到产品列表界面
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
}
