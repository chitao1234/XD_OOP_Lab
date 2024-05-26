//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_ORDER_H
#define E_COMMERCE_ORDER_H

#include <string>
#include <cinttypes>
#include <chrono>

namespace DataType {

    class Order {
    public:
        Order(uint64_t purchaseId,
              std::string username,
              double price,
              std::chrono::system_clock::time_point purchaseTime);

        [[nodiscard]] uint64_t getPurchaseId() const;

        [[nodiscard]] std::string getUsername() const;

        [[nodiscard]] double getPrice() const;

        [[nodiscard]] std::chrono::system_clock::time_point getPurchaseTime() const;

        static std::string serialize(const Order &order);

        static Order deserialize(const std::string &line);

        bool operator==(const Order &rhs) const;

    private:
        uint64_t purchaseId;
        std::string username;
        double price;
        std::chrono::system_clock::time_point purchaseTime;

    };

} // DataType

#endif //E_COMMERCE_ORDER_H
