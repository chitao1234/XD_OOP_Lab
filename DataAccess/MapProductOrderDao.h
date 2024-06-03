//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_MAPPRODUCTORDERDAO_H
#define E_COMMERCE_MAPPRODUCTORDERDAO_H

#include <map>
#include <vector>
#include "IProductOrderDao.h"

namespace DataAccess {
    // 订单-商品映射数据访问对象，使用map存储，文件持久化
    class MapProductOrderDao : public IProductOrderDao {
    public:
        explicit MapProductOrderDao(std::string filename);

        ~MapProductOrderDao() override;

        // 向订单中添加商品
        void addProductToOrder(uint64_t orderId, uint64_t productId, long quantity) override;

        // 移除订单中的商品
        void removeProductFromOrder(uint64_t orderId, uint64_t productId) override;

        // 获取订单中的所有商品
        std::vector<std::pair<uint64_t, long>> getProducts(uint64_t orderId) override;

        // 获取订单中某个商品的数量
        void updateProductQuantity(uint64_t orderId, uint64_t productId, long quantity) override;

        // 清空订单中的商品
        void clearOrder(uint64_t orderId) override;

        // 保存数据
        void save() override;

        // 加载数据
        bool load() override;

    private:
        std::string filename;
        std::map<uint64_t, std::vector<std::pair<uint64_t, long>>> orderProductMap;
    };

} // DataAccess

#endif //E_COMMERCE_MAPPRODUCTORDERDAO_H
