//
// Created by chi on 24/05/26.
//

#include <fstream>
#include "MapOrderDao.h"

namespace DataAccess {
    // 创建时加载数据
    MapOrderDao::MapOrderDao(std::string filename)
            : filename(std::move(filename)), nextIdValue(0) {
        MapOrderDao::load();
    }

    bool MapOrderDao::containOrder(uint64_t id) {
        return orders.find(id) != orders.end();
    }

    void MapOrderDao::addOrder(const DataType::Order &order) {
        orders.insert(std::make_pair(order.getPurchaseId(), order));
    }

    void MapOrderDao::removeOrder(uint64_t id) {
        orders.erase(id);
    }

    void MapOrderDao::updateOrder(DataType::Order &order) {
        if (!containOrder(order.getPurchaseId())) {
            throw std::runtime_error("Order not found");
        }
        orders.at(order.getPurchaseId()) = order;
    }

    DataType::Order MapOrderDao::getOrder(uint64_t id) {
        return orders.at(id);
    }

    std::vector<DataType::Order> MapOrderDao::filterOrders(std::optional<std::string> username) {
        std::vector<DataType::Order> result;
        for (const auto &pair: orders) {
            // 如果指定用户名，进行过滤
            if (!username.has_value() || pair.second.getUsername() == username.value()) {
                result.push_back(pair.second);
            }
        }
        return result;
    }

    uint64_t MapOrderDao::nextId() {
        return nextIdValue++;
    }

    void MapOrderDao::save() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file");
        }
        // 调用Order的序列化方法，将Order对象转换为字符串
        for (const auto &pair: orders) {
            file << DataType::Order::serialize(pair.second) << std::endl;
        }
    }

    bool MapOrderDao::load() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        orders.clear();
        std::string line;
        // 调用Order的反序列化方法，将字符串转换为Order对象
        while (std::getline(file, line)) {
            DataType::Order order = DataType::Order::deserialize(line);
            nextIdValue = std::max(nextIdValue, order.getPurchaseId());
            orders.insert({order.getPurchaseId(), order});
        }
        nextIdValue++;
        return true;
    }

    // 析构时保存数据
    MapOrderDao::~MapOrderDao() {
        MapOrderDao::save();
    }
}
