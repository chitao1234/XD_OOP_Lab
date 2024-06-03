//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_SHOPPINGCARTDAO_H
#define E_COMMERCE_SHOPPINGCARTDAO_H

#include <set>
#include <map>
#include <vector>
#include "IShoppingCartDao.h"

namespace DataAccess {
    // 购物车数据访问对象，使用map存储，文件持久化
    class ShoppingCartDao : public IShoppingCartDao {
    public:
        explicit ShoppingCartDao(std::string filename);

        ~ShoppingCartDao() override;

        // 列出购物车中的商品
        std::vector<std::pair<uint64_t, long>> listProductIds(std::string username) override;

        // 获取购物车中的商品数量
        long getProductQuantity(std::string username, uint64_t productId) override;

        // 删除购物车中的商品
        void removeProduct(std::string username, uint64_t productId) override;

        // 更新购物车中的商品数量
        void updateProductQuantity(std::string username, uint64_t productId, long quantity) override;

        // 清空购物车
        void clearCart(std::string username) override;

        // 保存数据
        void save() override;

        // 导出用户数据到文件
        bool exportToFile(std::string username, std::string filename) override;

        // 从文件导入用户数据
        bool importFromFile(std::string username, std::string filename) override;

        // 加载数据
        bool load() override;

    private:
        std::string filename;
        std::map<std::string, std::vector<std::pair<uint64_t, long>>> carts;
    };
}

#endif //E_COMMERCE_SHOPPINGCARTDAO_H
