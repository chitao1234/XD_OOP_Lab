//
// Created by chi on 24/04/29.
//

#include <iostream>
#include "CLIStateProductList.h"
#include "CLIStateProductDetail.h"
#include "Service/StorageService.h"

namespace UI {
    CLIStateProductList::CLIStateProductList(CLIUserInterface &userInterface, const std::vector<DataType::FullProduct> &products)
            : userInterface(userInterface), productDisplay(products) {
    }

    void CLIStateProductList::displayMenu() {
        std::cout << "Product List:" << std::endl;
    }

    void CLIStateProductList::handleUserInput() {
        // 使用ProductDisplay类来显示商品列表和选择商品
        std::optional<DataType::FullProduct> product = productDisplay.selectProduct(ProductDisplay::BRIEF);
        if (!product.has_value()) {
            userInterface.popState();
        } else {
            userInterface.pushState(new CLIStateProductDetail(userInterface, product.value()));
        }
    }
}