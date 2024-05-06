//
// Created by chi on 24/04/29.
//

#include <iostream>
#include <utility>
#include "CLIStateProductDetail.h"

void CLIStateProductDetail::displayMenu() {
    std::cout << "Product Detail" << std::endl;
    std::cout << "Name: " << product.getName() << std::endl;
    std::cout << "Price: " << product.getPrice() << std::endl;
    std::cout << "Description: " << product.getDescription() << std::endl;
    std::cout << "1. Add to cart\n"
                 "2. Buy\n"
                 "3. Back\n"
                 "Enter your choice: ";
    std::cout << std::endl;
}

CLIStateProductDetail::CLIStateProductDetail(CLIUserInterface &userInterface, Product product) : userInterface(
        userInterface), product(std::move(product)) {

}

void CLIStateProductDetail::handleUserInput() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            // StorageService::getInstance()->getLoggedInUser().addToCart(product);
            // TODO: cart
            std::cout << "Added to cart" << std::endl;
            break;
        case 2:
            // TODO: buy
            std::cout << "Bought" << std::endl;
        case 3:
            userInterface.popState();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    std::cout << std::endl;
}
