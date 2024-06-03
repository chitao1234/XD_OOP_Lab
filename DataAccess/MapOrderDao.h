//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_MAPORDERDAO_H
#define E_COMMERCE_MAPORDERDAO_H

#include <map>
#include "IOrderDao.h"

namespace DataAccess {
    // 订单数据访问对象，使用map缓存，文件持久化
    class MapOrderDao : public IOrderDao {
    public:
        explicit MapOrderDao(std::string filename);

        ~MapOrderDao() override;

        // 判断是否包含某个订单ID
        bool containOrder(uint64_t id) override;

        // 添加订单
        void addOrder(const DataType::Order &order) override;

        // 移除订单
        void removeOrder(uint64_t id) override;

        // 更新订单信息
        void updateOrder(DataType::Order &order) override;

        // 根据订单ID获取订单
        DataType::Order getOrder(uint64_t id) override;

        // 获取某个用户的所有订单
        std::vector<DataType::Order> filterOrders(std::optional<std::string> username) override;

        // 获取下一个订单ID
        uint64_t nextId() override;

        // 保存数据
        void save() override;

        // 加载数据
        bool load() override;
    private:
        std::string filename;
        std::map<uint64_t, DataType::Order> orders;
        uint64_t nextIdValue;
    };
}

#endif //E_COMMERCE_MAPORDERDAO_H
