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
    std::cout << std::endl;
}

CLIStateProductDetail::CLIStateProductDetail(CLIUserInterface &userInterface, Product product) : userInterface(
        userInterface), product(std::move(product)) {

}

void CLIStateProductDetail::handleUserInput() {
    std::cout << "1. Add to cart\n"
                 "2. Back\n"
                 "Enter your choice: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            // userInterface.getLoggedInUser().addToCart(product);
            // TODO: cart
            std::cout << "Added to cart" << std::endl;
            break;
        case 2:
            userInterface.popState();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    std::cout << std::endl;
}
