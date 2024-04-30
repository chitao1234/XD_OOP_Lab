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

    bool addProduct(const Product &product) override;

    std::optional<Product> getProduct(int productId) override;

    bool updateProduct(const Product &product) override;

    bool deleteProduct(int productId) override;

    std::vector<Product> listProducts() override;

private:
    IProductDao *productDao;
};


#endif //E_COMMERCE_MAPPRODUCTREPOSITORY_H
