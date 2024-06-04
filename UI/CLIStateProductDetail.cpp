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
        DataAccess::ICartOrderRepository &cart = SessionManager::getInstance()->getCartOrderRepository();
        switch (choice) {
            case 1: {
                // 如果未登录，提示登录，未登录只能浏览
                if (!SessionManager::getInstance()->getLoginStatus()) {
                    std::cout << "Please login first" << std::endl;
                    break;
                }
                std::cout << "Enter quantity: ";
                long quantity;
                Util::cinWrapper >> quantity;
                // 添加商品到购物车，使用购物车仓储
                cart.addProduct(product.getId(), quantity);
                std::cout << "Added to cart" << std::endl;
                break;
            }
            case 2: {
                if (!SessionManager::getInstance()->getLoginStatus()) {
                    std::cout << "Please login first" << std::endl;
                    break;
                }
                // 购买商品，使用购买服务
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
