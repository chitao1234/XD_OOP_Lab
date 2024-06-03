//
// Created by chi on 24/04/29.
//

#include "ProductRepository.h"

namespace DataAccess {
    // 使用数据访问对象工厂初始化数据访问对象
    ProductRepository::ProductRepository(IDaoFactory &daoFactory)
            : productDao(daoFactory.getProductDao()),
              categoryDao(daoFactory.getCategoryDao()) {}


    ProductRepository::~ProductRepository() {
        delete productDao;
        delete categoryDao;
    }

    // 添加商品信息和分类信息
    bool ProductRepository::addProduct(
            std::string name,
            std::string description,
            double price,
            long remainingStock,
            std::string category) {
        uint64_t categoryId;
        if (categoryDao->containCategory(category)) {
            categoryId = categoryDao->getId(category);
        } else {
            categoryId = categoryDao->nextId();
            categoryDao->addCategory(categoryId, category);
            categoryDao->save();
        }
        productDao->addProduct(
                {productDao->nextId(), std::move(name), std::move(description), price, remainingStock, categoryId});
        productDao->save();
        return true;
    }

    // 关联商品和分类信息
    std::optional<DataType::FullProduct> ProductRepository::getProduct(uint64_t productId) {
        if (!productDao->containProduct(productId)) {
            return std::nullopt;
        }
        DataType::Product product = productDao->getProduct(productId);
        return DataType::FullProduct{product, categoryDao->getCategory(product.getCategoryId())};
    }

    // 更新商品信息和分类信息
    bool ProductRepository::updateProduct(const DataType::FullProduct &product) {
        if (!productDao->containProduct(product.getId())) {
            return false;
        }
        if (product.getRemainingStock() < 0) {
            return false;
        }
        productDao->updateProduct(product);
        productDao->save();

        categoryDao->removeCategory(product.getCategoryId());
        categoryDao->addCategory(product.getCategoryId(), product.getCategory());
        categoryDao->save();
        return true;
    }

    bool ProductRepository::deleteProduct(uint64_t productId) {
        if (!productDao->containProduct(productId)) {
            return false;
        }
        productDao->removeProduct(productId);
        productDao->save();
        return true;
    }

    // 获取所有商品信息和分类信息，并进行关联得到完整商品
    std::vector<DataType::FullProduct> ProductRepository::listProducts() {
        std::vector<DataType::Product> products = productDao->getProducts();
        std::vector<DataType::FullProduct> result;
        result.reserve(products.size());
        for (const auto &product: products) {
            result.emplace_back(product, categoryDao->getCategory(product.getCategoryId()));
        }
        return result;
    }

    // 根据关键词搜索商品信息和分类信息，并进行关联得到完整商品
    std::vector<DataType::FullProduct> ProductRepository::searchProducts(std::string keyword) {
        std::vector<DataType::Product> products = productDao->getProducts(keyword);
        std::vector<DataType::FullProduct> result;
        result.reserve(products.size());
        for (const auto &product: products) {
            result.emplace_back(product, categoryDao->getCategory(product.getCategoryId()));
        }
        return result;
    }
}
