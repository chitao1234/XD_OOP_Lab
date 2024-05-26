//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_MAPPRODUCTREPOSITORY_H
#define E_COMMERCE_MAPPRODUCTREPOSITORY_H

#include "IProductRepository.h"
#include "IProductDao.h"
#include "IDaoFactory.h"

namespace DataAccess {
    class MapProductRepository : public IProductRepository {
    public:
        explicit MapProductRepository(IDaoFactory &daoFactory);

        ~MapProductRepository();

        bool addProduct(std::string name, std::string description, double price, long remainingStock) override;

        std::optional <DataType::Product> getProduct(uint64_t productId) override;

        bool updateProduct(const DataType::Product &product) override;

        bool deleteProduct(uint64_t productId) override;

        std::vector <DataType::Product> listProducts() override;

        std::vector <DataType::Product> searchProducts(std::string keyword) override;

    private:
        IProductDao *productDao;
    };
}


#endif //E_COMMERCE_MAPPRODUCTREPOSITORY_H
