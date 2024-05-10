//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_MAPPRODUCTREPOSITORY_H
#define E_COMMERCE_MAPPRODUCTREPOSITORY_H

#include "IProductRepository.h"
#include "IProductDao.h"

class MapProductRepository : public IProductRepository {
public:
    MapProductRepository();

    ~MapProductRepository();

    bool addProduct(std::string name, std::string description, double price, long remainingStock) override;

    std::optional<Product> getProduct(uint64_t productId) override;

    bool updateProduct(const Product &product) override;

    bool deleteProduct(uint64_t productId) override;

    std::vector<Product> listProducts() override;

    std::vector<Product> searchProducts(std::string keyword) override;

private:
    IProductDao *productDao;
};


#endif //E_COMMERCE_MAPPRODUCTREPOSITORY_H
