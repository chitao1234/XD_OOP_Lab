//
// Created by chi on 24/04/29.
//

#include <iostream>
#include <utility>
#include "CLIStateProductDetail.h"
#include "Service/SessionManager.h"

namespace UI {
    using Service::SessionManager;
    using DataAccess::IShoppingCartRepository;
    using DataType::Product;

    void CLIStateProductDetail::displayMenu() {
        std::cout << "Product Detail" << std::endl;
        std::cout << "Name: " << product.getName() << std::endl;
        std::cout << "Price: " << product.getPrice() << std::endl;
        std::cout << "Description: " << product.getDescription() << std::endl;
        std::cout << "1. Add to cart\n"
                     "2. Buy\n"
                     "3. Back\n"
                     "Enter your choice: ";
    }

    CLIStateProductDetail::CLIStateProductDetail(CLIUserInterface &userInterface, Product product) : userInterface(
            userInterface), product(std::move(product)) {

    }

    void CLIStateProductDetail::handleUserInput() {
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                if (!SessionManager::getInstance()->getLoginStatus()) {
                    std::cout << "Please login first" << std::endl;
                    break;
                }
                IShoppingCartRepository &cart = SessionManager::getInstance()->getShoppingCartRepository();
                std::cout << "Enter quantity: ";
                long quantity;
                std::cin >> quantity;
                cart.addProduct(product.getId(), quantity);
                std::cout << "Added to cart" << std::endl;
                break;
            }
            case 2:
                std::cout << "Bought" << std::endl;
                break;
            case 3:
                userInterface.popState();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        std::cout << std::endl;
    }
}
