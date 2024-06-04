//
// Created by chi on 24/05/26.
//

#include "Order.h"

#include <chrono>
#include <sstream>

namespace DataType {
    Order::Order(uint64_t purchaseId,
                 std::string username,
                 double price,
                 std::chrono::system_clock::time_point purchaseTime) :
            purchaseId(purchaseId),
            username(std::move(username)),
            price(price),
            purchaseTime(purchaseTime) {}

    [[nodiscard]] uint64_t Order::getPurchaseId() const {
        return purchaseId;
    }

    [[nodiscard]] std::string Order::getUsername() const {
        return username;
    }

    [[nodiscard]] double Order::getPrice() const {
        return price;
    }

    std::string Order::serialize(const Order &order) {
        // 采用CSV逗号分隔的方式序列化订单，分别为订单号、用户名、总价、购买时间（采用自纪元以来的毫秒数表示）
        std::ostringstream oss;
        oss << order.getPurchaseId() << ',';
        oss << order.getUsername() << ',';
        oss << order.getPrice() << ',';
        oss << std::chrono::duration_cast<std::chrono::milliseconds>(
                order.getPurchaseTime().time_since_epoch()).count();
        return oss.str();
    }

    Order Order::deserialize(const std::string &line) {
        std::istringstream iss(line);
        std::string id, user, productId, productQuantity, totalPrice, time;
        std::getline(iss, id, ',');
        std::getline(iss, user, ',');
        std::getline(iss, totalPrice, ',');
        std::getline(iss, time, ',');
        return {std::stoull(id),
                user,
                std::stod(totalPrice),
                std::chrono::system_clock::time_point(
                        std::chrono::milliseconds(std::stoll(time)))};
    }

    std::chrono::system_clock::time_point Order::getPurchaseTime() const {
        return purchaseTime;
    }

    bool Order::operator==(const Order &rhs) const {
        return purchaseId == rhs.purchaseId &&
               username == rhs.username &&
               price == rhs.price &&
               purchaseTime == rhs.purchaseTime;
    }
} // DataType