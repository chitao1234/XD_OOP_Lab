//
// Created by chi on 24/04/29.
//

#include <iostream>
#include "CLIStateProductList.h"
#include "CLIStateProductDetail.h"
#include "StorageService.h"

CLIStateProductList::CLIStateProductList(CLIUserInterface &userInterface, const std::vector <Product> &products)
        : userInterface(userInterface), productDisplay(products) {
}

void CLIStateProductList::displayMenu() {
    std::cout << "Product List:" << std::endl;
}

void CLIStateProductList::handleUserInput() {
    std::optional <Product> product = productDisplay.selectProduct(ProductDisplay::BRIEF);
    if (!product.has_value()) {
        userInterface.popState();
    } else {
        userInterface.pushState(new CLIStateProductDetail(userInterface, product.value()));
    }
}