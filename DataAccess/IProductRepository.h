//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_IPRODUCTREPOSITORY_H
#define E_COMMERCE_IPRODUCTREPOSITORY_H

#include "DataType/Product.h"
#include "DataType/FullProduct.h"
#include <vector>
#include <optional>

namespace DataAccess {
    // 商品数据仓储接口，包含商品分类名称，用于与外界交互
    class IProductRepository {
    public:
        // 接口需要使用虚析构函数
        ~IProductRepository() = default;

        // 添加完整商品，包括分类信息
        virtual bool addProduct(std::string name,
                                std::string description,
                                double price,
                                long remainingStock,
                                std::string category) = 0;

        // 获取完整商品，包括分类信息
        virtual std::optional<DataType::FullProduct> getProduct(uint64_t productId) = 0;

        // 更新商品信息，包括分类信息
        virtual bool updateProduct(const DataType::FullProduct &product) = 0;

        // 删除商品
        virtual bool deleteProduct(uint64_t productId) = 0;

        // 获取所有完整商品信息，包括分类信息
        virtual std::vector<DataType::FullProduct> listProducts() = 0;

        // 根据关键词获取完整商品，包括分类信息
        virtual std::vector<DataType::FullProduct> searchProducts(std::string keyword) = 0;
    };
}

#endif //E_COMMERCE_IPRODUCTREPOSITORY_H
