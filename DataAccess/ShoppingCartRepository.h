//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_SHOPPINGCARTREPOSITORY_H
#define E_COMMERCE_SHOPPINGCARTREPOSITORY_H

#include "IShoppingCartRepository.h"
#include "IProductRepository.h"
#include "IShoppingCartDao.h"
#include "IDaoFactory.h"

namespace DataAccess {
    class ShoppingCartRepository : public IShoppingCartRepository {
    public:
        explicit ShoppingCartRepository(IDaoFactory &daoFactory, IProductRepository &productRepository, std::string username);

        ~ShoppingCartRepository() override;

        std::vector <std::pair<DataType::Product, long>> listProducts() override;

        void addProduct(uint64_t productId, long quantity) override;

        void removeProduct(uint64_t productId) override;

        void updateProductQuantity(uint64_t productId, long quantity) override;

        void clearCart() override;

        bool exportToFile(std::string filename) override;

        bool importFromFile(std::string filename) override;

    private:
        std::string username;
        IProductRepository &productRepository;
        IShoppingCartDao *shoppingCartDao;
    };
}


#endif //E_COMMERCE_SHOPPINGCARTREPOSITORY_H
