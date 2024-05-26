//
// Created by chi on 24/05/26.
//

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstring>
#include "CLIStateOrderHistory.h"
#include "Service/StorageService.h"
#include "Service/SessionManager.h"

namespace UI {
    CLIStateOrderHistory::CLIStateOrderHistory(CLIUserInterface &userInterface)
            : userInterface(userInterface),
              start(),
              end() {}

    void CLIStateOrderHistory::displayMenu() {
        std::cout << "Order History" << std::endl;
        std::cout << "1. List orders\n"
                     "2. Set Filter\n"
                     "3. Back\n"
                     "Enter your choice: ";
    }

    void CLIStateOrderHistory::handleUserInput() {
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                DataAccess::ICartOrderRepository &repository = Service::SessionManager::getInstance()
                        ->getCartOrderRepository();
                std::optional<std::string> keyword{};
                std::optional<std::chrono::system_clock::time_point> startInput, endInput;
                if (!category.empty()) {
                    keyword = category;
                }
                if (start.tm_mday != 0) {
                    startInput = std::chrono::system_clock::from_time_t(std::mktime(&start));
                }
                if (end.tm_mday != 0) {
                    endInput = std::chrono::system_clock::from_time_t(std::mktime(&end));
                }
                std::vector<DataType::FullOrder> orders = repository.filterOrders(
                        keyword,
                        startInput,
                        endInput
                );
                for (const auto &order: orders) {
                    std::cout << "Order ID: " << order.getPurchaseId() << std::endl;
                    std::cout << "Username: " << order.getUsername() << std::endl;
                    std::cout << "Total: " << order.getPrice() << std::endl;
                    auto time = std::chrono::system_clock::to_time_t(order.getPurchaseTime());
                    std::cout << "Time: " << std::ctime(&time) << std::endl;
                    std::cout << "Items: " << std::endl;
                    if (order.getProducts().empty()) {
                        std::cout << "  No items" << std::endl;
                    }
                    for (const auto &item: order.getProducts()) {
                        std::cout << "  " << item.first.getName() << " x" << item.second << std::endl;
                    }
                    std::cout << std::endl;
                }
                break;
            }
            case 2: {
                std::cin.ignore();
                std::string timeStart, timeEnd;
                std::cout << "Enter Category (Enter for none): ";
                std::getline(std::cin, category);
                std::cout << "Enter Start Date (YYYY-MM-DD HH:MM:SS) (Enter for none): ";
                std::getline(std::cin, timeStart);
                std::cout << "Enter End Date (YYYY-MM-DD HH:MM:SS) (Enter for none): ";
                std::getline(std::cin, timeEnd);
                if (!timeStart.empty()) {
                    std::istringstream(timeStart) >> std::get_time(&start, "%Y-%m-%d %H:%M:%S");
                } else {
                    std::memset(&start, 0, sizeof(start));
                }
                if (!timeEnd.empty()) {
                    std::istringstream(timeEnd) >> std::get_time(&end, "%Y-%m-%d %H:%M:%S");
                } else {
                    std::memset(&end, 0, sizeof(end));
                }
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
} // UI