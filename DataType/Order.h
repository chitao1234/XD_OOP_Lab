//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_ORDER_H
#define E_COMMERCE_ORDER_H

#include <string>
#include <cinttypes>
#include <chrono>

namespace DataType {
    // 非完整订单类，不包含商品信息
    class Order {
    public:
        Order(uint64_t purchaseId,
              std::string username,
              double price,
              std::chrono::system_clock::time_point purchaseTime);

        [[nodiscard]] uint64_t getPurchaseId() const;

        [[nodiscard]] std::string getUsername() const;

        [[nodiscard]] double getPrice() const;

        // 采用 C++ 标准库的时间类表示时间
        [[nodiscard]] std::chrono::system_clock::time_point getPurchaseTime() const;

        // 序列化订单，用于保存到文件
        static std::string serialize(const Order &order);

        // 反序列化订单，用于从文件中读取
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
