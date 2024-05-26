//
// Created by chi on 24/05/06.
//

#include <iostream>
#include <algorithm>
#include "CLIStateCart.h"
#include "CLIStateCartMaintenance.h"
#include "Service/SessionManager.h"
#include "Service/StorageService.h"
#include "CLIStateOrderHistory.h"

namespace UI {
    using Service::SessionManager;
    using Service::StorageService;
    using DataType::Product;

    void CLIStateCart::displayMenu() {
        productDisplay.setProducts(SessionManager::getInstance()->getCartOrderRepository().listProducts());
        std::cout << "Cart List:\n";
        productDisplay.listProducts(ProductDisplay::BRIEF_WITH_NUMBER);
        std::cout << "Total Price (No coupon): "
                  << SessionManager::getInstance()->getPurchaseService().calculateTotalPrice(
                          SessionManager::getInstance()->getCartOrderRepository().listProducts(),
                          std::nullopt
                  )
                  << "\n\n";
        std::cout << "Selected:\n";
        ProductDisplay(selected).listProducts(ProductDisplay::BRIEF_WITH_NUMBER);
        std::cout << "Selected Price (No coupon): "
                  << SessionManager::getInstance()->getPurchaseService().calculateTotalPrice(selected,
                                                                                             std::nullopt)
                  << "\n\n";
        std::cout << std::endl;
        std::cout << "Cart Menu\n"
                     "1. Checkout\n"
                     "2. Select\n"
                     "3. Deselect\n"
                     "4. Manage Item\n"
                     "5. List Coupon\n"
                     "6. Redeem Coupon from Code\n"
                     "7. Export to File\n"
                     "8. Import from File\n"
                     "9. Check History\n"
                     "10. Back\n"
                     "Enter your choice: ";
    }

    void CLIStateCart::handleUserInput() {
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cout << "Checking out..." << std::endl;
                if (selected.empty()) {
                    std::cout << "No product selected" << std::endl;
                    break;
                }

                ProductDisplay(selected).listProducts(ProductDisplay::BRIEF_WITH_NUMBER);

                std::optional<DataType::Coupon> coupon = displayCoupons(true);
                if (coupon.has_value()) {
                    std::cout << "Coupon selected: " << coupon.value().getName() << " (" << coupon.value().getCode()
                              << "): Type: "
                              << DataType::Coupon::typeToString(coupon.value().getType()) << " Discount: "
                              << coupon.value().getValue() << std::endl;
                }

                std::cout << "Total Price: "
                          << SessionManager::getInstance()->getPurchaseService().calculateTotalPrice(selected, coupon)
                          << std::endl;
                std::cout << "Confirm? (y/n): ";
                char confirm;
                std::cin >> confirm;
                if (confirm != 'y' && confirm != 'Y') {
                    std::cout << "Checkout cancelled" << std::endl;
                    break;
                }

                if (Service::PurchaseResult result = SessionManager::getInstance()->getPurchaseService().purchase(
                        selected, coupon)) {
                    std::cout << "Checkout successful" << std::endl;
                    selected.clear();
                } else {
                    std::cout << "Checkout failed, reason: " << result.getMessage() << std::endl;
                }

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
            case 5: {
                displayCoupons(false);
                break;
            }
            case 6: {
                std::string code;
                std::cout << "Enter coupon code: ";
                std::cin >> code;
                if (StorageService::getInstance()
                        ->getCouponRepository().addCouponToUser(
                        SessionManager::getInstance()->getCurrentUser().value().getUsername(),
                        code)) {
                    std::cout << "Coupon redeemed." << std::endl;
                } else {
                    std::cout << "Invalid code." << std::endl;
                }
                break;
            }
            case 7: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                if (SessionManager::getInstance()->getCartOrderRepository().exportToFile(filename)) {
                    std::cout << "Exported to " << filename << std::endl;
                } else {
                    std::cout << "Export failed" << std::endl;
                }
                break;
            }
            case 8: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                if (SessionManager::getInstance()->getCartOrderRepository().importFromFile(filename)) {
                    std::cout << "Imported from " << filename << std::endl;
                } else {
                    std::cout << "Import failed" << std::endl;
                }
                break;
            }
            case 9:
                userInterface.pushState(new CLIStateOrderHistory(userInterface));
                break;
            case 10:
                userInterface.popState();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        std::cout << std::endl;
    }

    CLIStateCart::CLIStateCart(CLIUserInterface &userInterface) :
            userInterface(userInterface),
            productDisplay(SessionManager::getInstance()->getCartOrderRepository().listProducts()) {
    }

    std::optional<DataType::Coupon> CLIStateCart::displayCoupons(bool select) {
        std::vector<DataType::Coupon> coupons = StorageService::getInstance()
                ->getCouponRepository().getUserCoupons(
                SessionManager::getInstance()->getCurrentUser().value().getUsername());
        std::cout << "Coupon List:\n";
        if (coupons.empty()) {
            std::cout << "No coupon available" << std::endl;
            return std::nullopt;
        }
        int index = 1;
        for (const auto &coupon: coupons) {
            std::cout << index++ << ". " << coupon.getName() << " (" << coupon.getCode() << "): Type: "
                      << DataType::Coupon::typeToString(coupon.getType()) << " Discount: "
                      << coupon.getValue() << std::endl;
        }
        if (select) {
            std::cout << "Select a coupon: ";
            int choice;
            std::cin >> choice;
            if (choice < 1 || static_cast<size_t>(choice) > coupons.size()) {
                std::cout << "Invalid choice" << std::endl;
                return std::nullopt;
            }
            return coupons[choice - 1];
        } else {
            return std::nullopt;
        }
    }
}
