//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_IORDERDAO_H
#define E_COMMERCE_IORDERDAO_H

#include <vector>
#include <optional>
#include "DataType/Order.h"

namespace DataAccess {

    class IOrderDao {
    public:
        virtual ~IOrderDao() = default;

        virtual bool containOrder(uint64_t id) = 0;

        virtual void addOrder(const DataType::Order &order) = 0;

        virtual void removeOrder(uint64_t id) = 0;

        virtual void updateOrder(DataType::Order &order) = 0;

        virtual DataType::Order getOrder(uint64_t id) = 0;

        virtual std::vector<DataType::Order> filterOrders(std::optional<std::string> username) = 0;

        virtual uint64_t nextId() = 0;

        virtual void save() = 0;

        virtual bool load() = 0;

    };

} // DataAccess

#endif //E_COMMERCE_IORDERDAO_H
