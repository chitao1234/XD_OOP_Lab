//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_ISHOPPINGCARTDAO_H
#define E_COMMERCE_ISHOPPINGCARTDAO_H

#include <cstdint>
#include "DataType/Product.h"

namespace DataAccess {
    // 购物车数据访问对象接口，用于底层数据存储访问
    class IShoppingCartDao {
    public:
        // 接口需要使用虚析构函数
        virtual ~IShoppingCartDao() = default;

        // 获取购物车中的商品
        virtual std::vector<std::pair<uint64_t, long>> listProductIds(std::string username) = 0;

        // 获取购物车中的商品的数量
        virtual long getProductQuantity(std::string username, uint64_t productId) = 0;

        // 删除购物车中的商品
        virtual void removeProduct(std::string username, uint64_t productId) = 0;

        // 更新购物车中的商品数量
        virtual void updateProductQuantity(std::string username, uint64_t productId, long quantity) = 0;

        // 清空购物车
        virtual void clearCart(std::string username) = 0;

        // 保存数据
        virtual void save() = 0;

        // 导出用户数据到文件
        virtual bool exportToFile(std::string username, std::string filename) = 0;

        // 加载数据
        virtual bool load() = 0;

        // 从文件导入用户数据
        virtual bool importFromFile(std::string username, std::string filename) = 0;
    };
}


#endif //E_COMMERCE_ISHOPPINGCARTDAO_H
