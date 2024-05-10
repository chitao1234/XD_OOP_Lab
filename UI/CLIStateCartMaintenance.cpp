//
// Created by chi on 24/05/06.
//

#include <iostream>
#include "CLIStateCartMaintenance.h"
#include "Service/SessionManager.h"

CLIStateCartMaintenance::CLIStateCartMaintenance(CLIUserInterface &userInterface, std::pair<Product, long> product)
        : userInterface(userInterface), product(std::move(product)) {
}

void CLIStateCartMaintenance::displayMenu() {
    std::cout << "Product: " << product.first.getName() << " x" << product.second << std::endl;
    std::cout << "1. Manage quantity\n"
                 "2. Remove from cart\n"
                 "3. Back\n"
                 "Enter your choice: ";
}

void CLIStateCartMaintenance::handleUserInput() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            long quantity;
            std::cout << "Enter new quantity: ";
            std::cin >> quantity;
            SessionManager::getInstance()->getShoppingCartRepository()
                    .updateProductQuantity(product.first.getId(), quantity);
            product.second = quantity;
            break;
        }
        case 2: {
            std::cout << "Are you sure you want to remove this product from cart? (y/n): ";
            char confirm;
            std::cin >> confirm;
            if (confirm != 'y' && confirm != 'Y') {
                break;
            }
            SessionManager::getInstance()->getShoppingCartRepository()
                    .removeProduct(product.first.getId());
            userInterface.popState();
            break;
        }
        case 3: {
            userInterface.popState();
            break;
        }
        default: {
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }
}
