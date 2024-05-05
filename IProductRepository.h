//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_IPRODUCTREPOSITORY_H
#define E_COMMERCE_IPRODUCTREPOSITORY_H

#include "Product.h"
#include <vector>
#include <optional>

class IProductRepository {
public:
    ~IProductRepository() = default;

    virtual bool addProduct(std::string name, std::string description, double price, long remainingStock) = 0;

    virtual std::optional<Product> getProduct(int productId) = 0;

    virtual bool updateProduct(const Product &product) = 0;

    virtual bool deleteProduct(int productId) = 0;

    virtual std::vector<Product> listProducts() = 0;
};


#endif //E_COMMERCE_IPRODUCTREPOSITORY_H
