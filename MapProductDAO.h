//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_MAPPRODUCTDAO_H
#define E_COMMERCE_MAPPRODUCTDAO_H

#include <map>
#include "IProductDAO.h"


class MapProductDAO : public IProductDAO {
public:
    explicit MapProductDAO(std::string filename);

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
