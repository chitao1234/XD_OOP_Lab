//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_IPRODUCTDAO_H
#define E_COMMERCE_IPRODUCTDAO_H

#include <cinttypes>
#include <vector>
#include "DataType/Product.h"

namespace DataAccess {
    // 商品数据访问对象接口，不包含商品分类名称，用于底层数据存储访问
    class IProductDao {
    public:
        // 接口需要使用虚析构函数
        virtual ~IProductDao() = default;

        // 判断是否包含某个商品ID
        virtual bool containProduct(uint64_t id) = 0;

        // 添加商品
        virtual void addProduct(const DataType::Product &product) = 0;

        // 移除商品
        virtual void removeProduct(uint64_t id) = 0;

        // 更新商品信息
        virtual void updateProduct(const DataType::Product &product) = 0;

        // 获取商品
        virtual DataType::Product getProduct(uint64_t id) = 0;

        // 获取所有商品
        virtual std::vector<DataType::Product> getProducts() = 0;

        // 根据关键词获取商品
        virtual std::vector<DataType::Product> getProducts(std::string query) = 0;

        // 获取下一个商品ID
        virtual uint64_t nextId() = 0;

        // 保存数据
        virtual void save() = 0;

        // 加载数据
        virtual bool load() = 0;
    };
}


#endif //E_COMMERCE_IPRODUCTDAO_H
