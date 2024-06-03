//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_ICARTORDERREPOSITORY_H
#define E_COMMERCE_ICARTORDERREPOSITORY_H

#include <vector>
#include <chrono>
#include <optional>
#include <string>
#include "DataType/FullProduct.h"
#include "DataType/FullOrder.h"


namespace DataAccess {
    // 购物车与订单的通用数据仓储接口，用于与外界交互
    class ICartOrderRepository {
    public:
        // 接口需要使用虚析构函数
        virtual ~ICartOrderRepository() = default;

        // 获取购物车中的商品
        virtual std::vector<std::pair<DataType::FullProduct, long>> listProducts() = 0;

        // 添加商品到购物车
        virtual void addProduct(uint64_t productId, long quantity) = 0;

        // 从购物车中移除商品
        virtual void removeProduct(uint64_t productId) = 0;

        // 更新购物车中商品的数量
        virtual void updateProductQuantity(uint64_t productId, long quantity) = 0;

        // 清空购物车
        virtual void clearCart() = 0;

        // 从文件导入购物车
        virtual bool exportToFile(std::string filename) = 0;

        // 导出购物车到文件
        virtual bool importFromFile(std::string filename) = 0;

        // 添加新的订单
        virtual void addOrder(std::vector<std::pair<DataType::FullProduct, long>> products, double price) = 0;

        // 将不完整订单与实际商品进行关联，若使用数据库则为多表查询
        virtual DataType::FullOrder getFullOrder(const DataType::Order &order) = 0;

        // 根据关键字、起始时间、结束时间筛选订单
        virtual std::vector<DataType::FullOrder> filterOrders(
                std::optional<std::string> keyword,
                std::optional<std::chrono::system_clock::time_point> start,
                std::optional<std::chrono::system_clock::time_point> end) = 0;
    };
}


#endif //E_COMMERCE_ICARTORDERREPOSITORY_H
