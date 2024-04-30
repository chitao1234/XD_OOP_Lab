//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_MAPPRODUCTDAO_H
#define E_COMMERCE_MAPPRODUCTDAO_H

#include <map>
#include "IProductDao.h"


class MapProductDao : public IProductDao {
public:
    explicit MapProductDao(std::string filename);

    ~MapProductDao() override;

    bool containProduct(uint64_t id) override;

    void addProduct(const Product &product) override;

    void removeProduct(uint64_t id) override;

    void updateProduct(const Product &product) override;

    Product getProduct(uint64_t id) override;

    std::vector<Product> getProducts() override;

    std::vector<Product> getProducts(std::string query) override;

    void save() override;

    bool load() override;

private:
    std::string filename;
    std::map<uint64_t, Product> products;
};


#endif //E_COMMERCE_MAPPRODUCTDAO_H
