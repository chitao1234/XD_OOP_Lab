//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_CARTORDERREPOSITORY_H
#define E_COMMERCE_CARTORDERREPOSITORY_H

#include "ICartOrderRepository.h"
#include "IProductRepository.h"
#include "IShoppingCartDao.h"
#include "IDaoFactory.h"
#include "IOrderDao.h"
#include "IProductOrderDao.h"

namespace DataAccess {
    // 购物车与订单的数据仓储的具体实现，使用底层数据访问对象实现
    class CartOrderRepository : public ICartOrderRepository {
    public:
        // 构造函数，传入数据访问对象工厂、商品数据仓储、用户名
        CartOrderRepository(IDaoFactory &daoFactory, IProductRepository &productRepository, std::string username);

        ~CartOrderRepository() override;

        // 获取购物车中的商品
        std::vector <std::pair<DataType::FullProduct, long>> listProducts() override;

        // 添加商品到购物车
        void addProduct(uint64_t productId, long quantity) override;

        // 从购物车中移除商品
        void removeProduct(uint64_t productId) override;

        // 更新购物车中商品的数量
        void updateProductQuantity(uint64_t productId, long quantity) override;

        // 清空购物车
        void clearCart() override;

        // 从文件导入购物车
        bool exportToFile(std::string filename) override;

        // 导出购物车到文件
        bool importFromFile(std::string filename) override;

        // 添加新的订单
        void addOrder(std::vector<std::pair<DataType::FullProduct, long>> products, double price) override;

        // 将不完整订单与实际商品进行关联，使用两个数据访问对象进行多表查询
        DataType::FullOrder getFullOrder(const DataType::Order& order) override;

        // 根据关键字、起始时间、结束时间筛选订单
        std::vector<DataType::FullOrder> filterOrders(
                std::optional<std::string> keyword,
                std::optional<std::chrono::system_clock::time_point> start,
                std::optional<std::chrono::system_clock::time_point> end) override;

    private:
        // 用户名
        std::string username;
        // 商品数据仓储
        IProductRepository &productRepository;
        // 数据访问对象
        IShoppingCartDao *shoppingCartDao;
        IOrderDao *orderDao;
        IProductOrderDao *productOrderDao;
    };
}


#endif //E_COMMERCE_CARTORDERREPOSITORY_H
