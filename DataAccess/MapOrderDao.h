//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_MAPORDERDAO_H
#define E_COMMERCE_MAPORDERDAO_H

#include <map>
#include "IOrderDao.h"

namespace DataAccess {

    class MapOrderDao : public IOrderDao {
    public:
        explicit MapOrderDao(std::string filename);

        ~MapOrderDao() override;

        bool containOrder(uint64_t id) override;

        void addOrder(const DataType::Order &order) override;

        void removeOrder(uint64_t id) override;

        void updateOrder(DataType::Order &order) override;

        DataType::Order getOrder(uint64_t id) override;

        std::vector<DataType::Order> filterOrders(std::optional<std::string> username) override;

        uint64_t nextId() override;

        void save() override;

        bool load() override;
    private:
        std::string filename;
        std::map<uint64_t, DataType::Order> orders;
        uint64_t nextIdValue;
    };
}

#endif //E_COMMERCE_MAPORDERDAO_H
