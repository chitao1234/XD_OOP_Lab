//
// Created by chi on 24/04/29.
//

#include "MapProductRepository.h"

#include "MapProductDao.h"

namespace DataAccess {
    using DataType::FullProduct;

    MapProductRepository::MapProductRepository(IDaoFactory &daoFactory)
            : productDao(daoFactory.getProductDao()),
              categoryDao(daoFactory.getCategoryDao()) {}


    MapProductRepository::~MapProductRepository() {
        delete productDao;
        delete categoryDao;
    }

    bool
    MapProductRepository::addProduct(std::string name,
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

    std::optional<FullProduct> MapProductRepository::getProduct(uint64_t productId) {
        if (!productDao->containProduct(productId)) {
            return std::nullopt;
        }
        DataType::Product product = productDao->getProduct(productId);
        return FullProduct{product, categoryDao->getCategory(product.getCategoryId())};
    }

    bool MapProductRepository::updateProduct(const FullProduct &product) {
        if (!productDao->containProduct(product.getId())) {
            return false;
        }
        if (product.getRemainingStock() < 0) {
            return false;
        }
        productDao->updateProduct(product);
        productDao->save();
        return true;
    }

    bool MapProductRepository::deleteProduct(uint64_t productId) {
        if (!productDao->containProduct(productId)) {
            return false;
        }
        productDao->removeProduct(productId);
        productDao->save();
        return true;
    }

    std::vector<FullProduct> MapProductRepository::listProducts() {
        std::vector<DataType::Product> products = productDao->getProducts();
        std::vector<FullProduct> result;
        result.reserve(products.size());
        for (const auto &product: products) {
            result.emplace_back(product, categoryDao->getCategory(product.getCategoryId()));
        }
        return result;
    }

    std::vector<FullProduct> MapProductRepository::searchProducts(std::string keyword) {
        std::vector<DataType::Product> products = productDao->getProducts(keyword);
        std::vector<FullProduct> result;
        result.reserve(products.size());
        for (const auto &product: products) {
            result.emplace_back(product, categoryDao->getCategory(product.getCategoryId()));
        }
    }
}
