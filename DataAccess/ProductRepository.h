//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_PRODUCTREPOSITORY_H
#define E_COMMERCE_PRODUCTREPOSITORY_H

#include "IProductRepository.h"
#include "IProductDao.h"
#include "IDaoFactory.h"

namespace DataAccess {
    // 商品数据仓储实现，使用数据访问对象实现具体的数据操作，与底层数据存储方式解耦
    class ProductRepository : public IProductRepository {
    public:
        explicit ProductRepository(IDaoFactory &daoFactory);

        ~ProductRepository();

        // 添加商品信息和分类信息
        bool addProduct(std::string name,
                        std::string description,
                        double price,
                        long remainingStock,
                        std::string category) override;

        // 获取完整商品，包含商品和分类信息
        std::optional<DataType::FullProduct> getProduct(uint64_t productId) override;

        // 更新商品信息和分类信息
        bool updateProduct(const DataType::FullProduct &product) override;

        // 删除商品
        bool deleteProduct(uint64_t productId) override;

        // 获取所有完整商品信息，包括分类信息
        std::vector<DataType::FullProduct> listProducts() override;

        // 根据关键词获取完整商品，包括分类信息
        std::vector<DataType::FullProduct> searchProducts(std::string keyword) override;

    private:
        IProductDao *productDao;
        ICategoryDao *categoryDao;
    };
}


#endif //E_COMMERCE_PRODUCTREPOSITORY_H
