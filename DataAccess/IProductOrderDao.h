//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_IPRODUCTORDERDAO_H
#define E_COMMERCE_IPRODUCTORDERDAO_H

#include <string>
#include <cinttypes>

namespace DataAccess {
    // 订单-商品映射数据访问对象接口，用于底层数据存储访问
    class IProductOrderDao {
    public:
        // 接口需要使用虚析构函数
        virtual ~IProductOrderDao() = default;

        // 向订单中添加商品
        virtual void addProductToOrder(uint64_t orderId, uint64_t productId, long quantity) = 0;

        // 移除订单中的商品
        virtual void removeProductFromOrder(uint64_t orderId, uint64_t productId) = 0;

        // 获取订单中的所有商品
        virtual std::vector<std::pair<uint64_t, long>> getProducts(uint64_t orderId) = 0;

        // 获取订单中某个商品的数量
        virtual void updateProductQuantity(uint64_t orderId, uint64_t productId, long quantity) = 0;

        // 清空订单中的商品
        virtual void clearOrder(uint64_t orderId) = 0;

        // 保存数据
        virtual void save() = 0;

        // 加载数据
        virtual bool load() = 0;
    };
}

#endif //E_COMMERCE_IPRODUCTORDERDAO_H
