//
// Created by chi on 24/05/13.
//

#include <iostream>
#include "CLIStateCouponMaintenance.h"
#include "Service/StorageService.h"

namespace UI {
    using DataType::Coupon;

    CLIStateCouponMaintenance::CLIStateCouponMaintenance(CLIUserInterface &userInterface)
            : userInterface(userInterface) {
    }

    void CLIStateCouponMaintenance::displayMenu() {
        std::cout << "Coupon Maintenance:\n"
                     "1. Add Coupon\n"
                     "2. Add Coupon to User\n"
                     "3. Remove Coupon\n"
                     "4. Remove Coupon from User\n"
                     "5. List Coupons\n"
                     "6. List Coupons from User\n"
                     "7. Back\n"
                     "Enter your choice: ";
    }

    void CLIStateCouponMaintenance::handleUserInput() {
        int choice;
        std::cin >> choice;
        DataAccess::ICouponRepository &couponRepository = Service::StorageService::getInstance()->getCouponRepository();
        switch (choice) {
            case 1: {
                std::string code, name;
                double discount;
                int type;
                std::cout << "Enter coupon name: ";
                std::cin >> name;
                std::cout << "1. Percentage discount\n"
                             "2. Fixed discount\n"
                             "Enter coupon type: ";
                std::cin >> type;
                if (type > 2 || type < 1) {
                    std::cout << "Invalid choice" << std::endl;
                    break;
                }
                std::cout << "Enter coupon code: ";
                std::cin >> code;
                std::cout << "Enter discount: ";
                std::cin >> discount;
                couponRepository.addCoupon(
                        {name, Coupon::Type(type), discount, code});
                std::cout << "Coupon added" << std::endl;
                break;
            }
            case 2: {
                displayCouponList();
                std::string username;
                uint64_t couponId;
                std::cout << "Enter username: ";
                std::cin >> username;
                displayUserCouponList(username);
                std::cout << "Enter coupon id: ";
                std::cin >> couponId;
                couponRepository.addCouponToUser(username, couponId);
                std::cout << "Coupon added to user" << std::endl;
                break;
            }
            case 3: {
                displayCouponList();
                uint64_t couponId;
                std::cout << "Enter coupon id: ";
                std::cin >> couponId;
                couponRepository.removeCoupon(couponId);
                std::cout << "Coupon removed" << std::endl;
                break;
            }
            case 4: {
                std::string username;
                uint64_t couponId;
                std::cout << "Enter username: ";
                std::cin >> username;
                displayUserCouponList(username);
                std::cout << "Enter coupon id: ";
                std::cin >> couponId;
                couponRepository.removeCouponFromUser(username, couponId);
                std::cout << "Coupon removed from user" << std::endl;
                break;
            }
            case 5: {
                displayCouponList();
                break;
            }
            case 6: {
                std::string username;
                std::cout << "Enter username: ";
                std::cin >> username;
                displayUserCouponList(username);
                break;
            }
            case 7: {
                userInterface.popState();
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }

    void CLIStateCouponMaintenance::displayCouponList(const std::vector<DataType::Coupon> &couponList) {
        for (auto &coupon: couponList) {
            std::cout << "Coupon ID: " << coupon.getId() << std::endl;
            std::cout << "Coupon Name: " << coupon.getName() << std::endl;
            std::cout << "Coupon Code: " << coupon.getCode() << std::endl;
            std::cout << "Coupon Type: " << Coupon::typeToString(coupon.getType())
                      << std::endl;
            std::cout << "Coupon Discount: " << coupon.getValue() << std::endl;
            std::cout << std::endl;
        }
    }

    void CLIStateCouponMaintenance::displayCouponList() {
        auto coupons = Service::StorageService::getInstance()->getCouponRepository().getCoupons();
        displayCouponList(coupons);
    }

    void CLIStateCouponMaintenance::displayUserCouponList(const std::string &username) {
        auto coupons = Service::StorageService::getInstance()->getCouponRepository().getUserCoupons(username);
        displayCouponList(coupons);
    }
} // UI