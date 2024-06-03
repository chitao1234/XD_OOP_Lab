//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_IORDERDAO_H
#define E_COMMERCE_IORDERDAO_H

#include <vector>
#include <optional>
#include "DataType/Order.h"

namespace DataAccess {
    // 订单数据访问对象接口，用于底层数据存储访问
    class IOrderDao {
    public:
        // 接口需要使用虚析构函数
        virtual ~IOrderDao() = default;

        // 判断是否包含某个订单ID
        virtual bool containOrder(uint64_t id) = 0;

        // 添加订单
        virtual void addOrder(const DataType::Order &order) = 0;

        // 移除订单
        virtual void removeOrder(uint64_t id) = 0;

        // 更新订单信息
        virtual void updateOrder(DataType::Order &order) = 0;

        // 获取订单
        virtual DataType::Order getOrder(uint64_t id) = 0;

        // 获取某个用户的所有订单
        virtual std::vector<DataType::Order> filterOrders(std::optional<std::string> username) = 0;

        // 获取下一个订单ID
        virtual uint64_t nextId() = 0;

        // 保存数据
        virtual void save() = 0;

        // 加载数据
        virtual bool load() = 0;

    };

} // DataAccess

#endif //E_COMMERCE_IORDERDAO_H
