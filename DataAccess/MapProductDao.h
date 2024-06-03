//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_MAPPRODUCTDAO_H
#define E_COMMERCE_MAPPRODUCTDAO_H

#include <map>
#include "IProductDao.h"


namespace DataAccess {
    // 商品数据访问对象，使用map缓存，文件持久化
    class MapProductDao : public IProductDao {
    public:
        explicit MapProductDao(std::string filename);

        ~MapProductDao() override;

        // 判断是否包含某个商品ID
        bool containProduct(uint64_t id) override;

        // 添加商品
        void addProduct(const DataType::Product &product) override;

        // 移除商品
        void removeProduct(uint64_t id) override;

        // 更新商品信息
        void updateProduct(const DataType::Product &product) override;

        // 获取商品
        DataType::Product getProduct(uint64_t id) override;

        // 获取所有商品
        std::vector <DataType::Product> getProducts() override;

        // 根据关键词获取商品
        std::vector <DataType::Product> getProducts(std::string query) override;

        // 获取下一个商品ID
        uint64_t nextId() override;

        // 保存数据
        void save() override;

        // 加载数据
        bool load() override;

    private:
        uint64_t lastId;
        std::string filename;
        std::map <uint64_t, DataType::Product> products;
    };
}

#endif //E_COMMERCE_MAPPRODUCTDAO_H
