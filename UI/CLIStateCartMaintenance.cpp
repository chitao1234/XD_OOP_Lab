//
// Created by chi on 24/05/06.
//

#include <iostream>
#include "CLIStateCartMaintenance.h"
#include "Service/SessionManager.h"
#include "Util/ErrorCheckingInputStream.h"

namespace UI {
    using Service::SessionManager;

    CLIStateCartMaintenance::CLIStateCartMaintenance(CLIUserInterface &userInterface,
                                                     std::pair<DataType::FullProduct, long> product)
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
        Util::cinWrapper >> choice;
        switch (choice) {
            case 1: {
                long quantity;
                std::cout << "Enter new quantity: ";
                Util::cinWrapper >> quantity;
                // 使用购物车订单仓储更新商品数量
                SessionManager::getInstance()->getCartOrderRepository()
                        .updateProductQuantity(product.first.getId(), quantity);
                product.second = quantity;
                break;
            }
            case 2: {
                std::cout << "Are you sure you want to remove this product from cart? (y/n): ";
                char confirm;
                Util::cinWrapper >> confirm;
                if (confirm != 'y' && confirm != 'Y') {
                    break;
                }
                // 使用购物车订单仓储移除商品
                SessionManager::getInstance()->getCartOrderRepository()
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
}
