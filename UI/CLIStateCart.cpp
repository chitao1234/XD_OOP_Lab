//
// Created by chi on 24/05/06.
//

#include <iostream>
#include <algorithm>
#include "CLIStateCart.h"
#include "CLIStateCartMaintenance.h"
#include "Service/SessionManager.h"

namespace UI {
    using Service::SessionManager;
    using DataType::Product;

    void CLIStateCart::displayMenu() {
        productDisplay.setProducts(SessionManager::getInstance()->getShoppingCartRepository().listProducts());
        std::cout << "Cart List:\n";
        productDisplay.listProducts(ProductDisplay::BRIEF_WITH_NUMBER);
        std::cout << "Selected:\n";
        ProductDisplay(selected).listProducts(ProductDisplay::BRIEF_WITH_NUMBER);
        std::cout << std::endl;
        std::cout << "Cart Menu\n"
                     "1. Checkout\n"
                     "2. Select\n"
                     "3. Deselect\n"
                     "4. Manage\n"
                     "5. Back\n"
                     "Enter your choice: ";
    }

    void CLIStateCart::handleUserInput() {
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                // TODO: checkout
                std::cout << "Checking out..." << std::endl;
                for (const auto &product: selected) {
                    SessionManager::getInstance()->getShoppingCartRepository().removeProduct(product.first.getId());
                }
                selected.clear();
                break;
            }
            case 2: {
                std::vector<std::pair<Product, long>> append = productDisplay.selectProductsWithNumber(
                        ProductDisplay::BRIEF_WITH_NUMBER);
                selected.reserve(selected.size() + append.size());
                for (const auto &product: append) {
                    if (std::find(selected.begin(), selected.end(), product) != selected.end()) {
                        std::cout << "Product " << product.first.getName() << " already selected" << std::endl;
                        continue;
                    }
                    selected.push_back(product);
                }
                break;
            }
            case 3: {
                std::vector<std::pair<Product, long>> remove = ProductDisplay(selected).selectProductsWithNumber(
                        ProductDisplay::BRIEF_WITH_NUMBER);
                for (const auto &product: remove) {
                    selected.erase(std::remove(selected.begin(), selected.end(), product), selected.end());
                }
                break;
            }
            case 4: {
                std::optional<std::pair<Product, long>> product = productDisplay.selectProductWithNumber(
                        ProductDisplay::BRIEF_WITH_NUMBER);
                if (!product.has_value()) {
                    std::cout << "Invalid choice" << std::endl;
                    break;
                }
                userInterface.pushState(new CLIStateCartMaintenance(userInterface, product.value()));
                break;
            }
            case 5:
                userInterface.popState();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        std::cout << std::endl;
    }

    CLIStateCart::CLIStateCart(CLIUserInterface &userInterface) :
            userInterface(userInterface),
            productDisplay(SessionManager::getInstance()->getShoppingCartRepository().listProducts()) {
    }
}
