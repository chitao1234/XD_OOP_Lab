//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_IPRODUCTDAO_H
#define E_COMMERCE_IPRODUCTDAO_H

#include <cinttypes>
#include <vector>
#include "../DataType/Product.h"

class IProductDao {
public:
    virtual ~IProductDao() = default;

    virtual bool containProduct(uint64_t id) = 0;

    virtual void addProduct(const Product &product) = 0;

    virtual void removeProduct(uint64_t id) = 0;

    virtual void updateProduct(const Product &product) = 0;

    virtual Product getProduct(uint64_t id) = 0;

    virtual std::vector<Product> getProducts() = 0;

    virtual std::vector<Product> getProducts(std::string query) = 0;

    virtual uint64_t nextId() = 0;

    virtual void save() = 0;

    virtual bool load() = 0;
};


#endif //E_COMMERCE_IPRODUCTDAO_H
