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
    class IProductRepository {
    public:
        ~IProductRepository() = default;

        virtual bool addProduct(std::string name,
                                std::string description,
                                double price,
                                long remainingStock,
                                std::string category) = 0;

        virtual std::optional<DataType::FullProduct> getProduct(uint64_t productId) = 0;

        virtual bool updateProduct(const DataType::FullProduct &product) = 0;

        virtual bool deleteProduct(uint64_t productId) = 0;

        virtual std::vector<DataType::FullProduct> listProducts() = 0;

        virtual std::vector<DataType::FullProduct> searchProducts(std::string keyword) = 0;
    };
}

#endif //E_COMMERCE_IPRODUCTREPOSITORY_H
