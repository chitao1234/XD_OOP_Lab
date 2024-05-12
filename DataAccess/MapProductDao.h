//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_MAPPRODUCTDAO_H
#define E_COMMERCE_MAPPRODUCTDAO_H

#include <map>
#include "IProductDao.h"


namespace DataAccess {
    class MapProductDao : public IProductDao {
    public:
        explicit MapProductDao(std::string filename);

        ~MapProductDao() override;

        bool containProduct(uint64_t id) override;

        void addProduct(const DataType::Product &product) override;

        void removeProduct(uint64_t id) override;

        void updateProduct(const DataType::Product &product) override;

        DataType::Product getProduct(uint64_t id) override;

        std::vector <DataType::Product> getProducts() override;

        std::vector <DataType::Product> getProducts(std::string query) override;

        uint64_t nextId() override;

        void save() override;

        bool load() override;

    private:
        uint64_t lastId;
        std::string filename;
        std::map <uint64_t, DataType::Product> products;
    };
}

#endif //E_COMMERCE_MAPPRODUCTDAO_H
