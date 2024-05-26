//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_IPRODUCTREPOSITORY_H
#define E_COMMERCE_IPRODUCTREPOSITORY_H

#include "DataType/Product.h"
#include <vector>
#include <optional>

namespace DataAccess {
    class IProductRepository {
    public:
        ~IProductRepository() = default;

        virtual bool addProduct(std::string name, std::string description, double price, long remainingStock) = 0;

        virtual std::optional<DataType::Product> getProduct(uint64_t productId) = 0;

        virtual bool updateProduct(const DataType::Product &product) = 0;

        virtual bool deleteProduct(uint64_t productId) = 0;

        virtual std::vector<DataType::Product> listProducts() = 0;

        virtual std::vector<DataType::Product> searchProducts(std::string keyword) = 0;
    };
}

#endif //E_COMMERCE_IPRODUCTREPOSITORY_H
