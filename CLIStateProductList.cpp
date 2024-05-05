//
// Created by chi on 24/04/29.
//

#include <iostream>
#include "CLIStateProductList.h"
#include "CLIStateProductDetail.h"

CLIStateProductList::CLIStateProductList(CLIUserInterface &userInterface, const std::vector<Product> &products)
        : userInterface(userInterface), products(products) {
}

void CLIStateProductList::displayMenu() {
    std::cout << "Product List" << std::endl;
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << i + 1 << ". " << products[i].getName() << std::endl;
        std::cout << "   Price: " << products[i].getPrice() << std::endl;
        std::cout << std::endl;
    }
}

void CLIStateProductList::handleUserInput() {
    std::cout << "Enter product number to view details, or 'b' to go back and 's' to search: ";
    std::string input;
    std::cin >> input;
    if (input == "b") {
        userInterface.popState();
    } else if (input == "s") {
        std::string search;
        std::cout << "Enter search query: ";
        std::cin >> search;
        userInterface.pushState(new CLIStateProductList(userInterface,
                                                        userInterface.getProductRepository()
                                                                .searchProducts(search)));
    } else {
        long productNumber = std::stol(input) - 1;
        if (productNumber >= 0 && (size_t) productNumber < products.size()) {
            userInterface.pushState(new CLIStateProductDetail(userInterface, products[productNumber]));
        } else {
            std::cout << "Invalid product number" << std::endl;
        }
    }
}