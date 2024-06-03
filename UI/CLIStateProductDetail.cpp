//
// Created by chi on 24/04/29.
//

#include <iostream>
#include "CLIStateProductDetail.h"
#include "Service/SessionManager.h"
#include "Service/StorageService.h"
#include "Util/ErrorCheckingInputStream.h"

namespace UI {
    using Service::SessionManager;
    using Service::StorageService;
    using DataAccess::ICartOrderRepository;

    void CLIStateProductDetail::displayMenu() {
        std::cout << "Product Detail" << std::endl;
        std::cout << "Name: " << product.getName() << std::endl;
        std::cout << "Original Price: " << product.getPrice() << std::endl;
        std::cout << "Actual Price after Discount: " << product.getActualPrice() << std::endl;
        std::cout << "Description: " << product.getDescription() << std::endl;
        std::cout << "Category: " << product.getCategory() << std::endl;
        std::cout << "1. Add to cart\n"
                     "2. Buy\n"
                     "3. Back\n"
                     "Enter your choice: ";
    }

    CLIStateProductDetail::CLIStateProductDetail(CLIUserInterface &userInterface, DataType::FullProduct product) : userInterface(
            userInterface), product(std::move(product)) {

    }

    void CLIStateProductDetail::handleUserInput() {
        int choice;
        Util::cinWrapper >> choice;
        switch (choice) {
            case 1: {
                if (!SessionManager::getInstance()->getLoginStatus()) {
                    std::cout << "Please login first" << std::endl;
                    break;
                }
                ICartOrderRepository &cart = SessionManager::getInstance()->getCartOrderRepository();
                std::cout << "Enter quantity: ";
                long quantity;
                Util::cinWrapper >> quantity;
                cart.addProduct(product.getId(), quantity);
                std::cout << "Added to cart" << std::endl;
                break;
            }
            case 2: {
                if (!SessionManager::getInstance()->getLoginStatus()) {
                    std::cout << "Please login first" << std::endl;
                    break;
                }
                ICartOrderRepository &cart = SessionManager::getInstance()->getCartOrderRepository();
                if (Service::PurchaseService(cart, StorageService::getInstance()->getCouponRepository()).purchase(
                        product)) {
                    std::cout << "Bought" << std::endl;
                } else {
                    std::cout << "Failed to buy" << std::endl;
                }
                break;
            }
            case 3:
                userInterface.popState();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        std::cout << std::endl;
    }
}
