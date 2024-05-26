//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_SHOPPINGCARTREPOSITORY_H
#define E_COMMERCE_SHOPPINGCARTREPOSITORY_H

#include "IShoppingCartRepository.h"
#include "IProductRepository.h"
#include "IShoppingCartDao.h"
#include "IDaoFactory.h"
#include "IOrderDao.h"
#include "IProductOrderDao.h"

namespace DataAccess {
    class ShoppingCartRepository : public IShoppingCartRepository {
    public:
        ShoppingCartRepository(IDaoFactory &daoFactory, IProductRepository &productRepository, std::string username);

        ~ShoppingCartRepository() override;

        std::vector <std::pair<DataType::Product, long>> listProducts() override;

        void addProduct(uint64_t productId, long quantity) override;

        void removeProduct(uint64_t productId) override;

        void updateProductQuantity(uint64_t productId, long quantity) override;

        void clearCart() override;

        bool exportToFile(std::string filename) override;

        bool importFromFile(std::string filename) override;

        void addOrder(std::vector<std::pair<DataType::Product, long>> products, double price) override;

        DataType::FullOrder getFullOrder(uint64_t orderId);

        std::vector<DataType::FullOrder> filterOrders(
                std::optional<std::string> keyword,
                std::optional<std::chrono::system_clock::time_point> start,
                std::optional<std::chrono::system_clock::time_point> end) override;

    private:
        std::string username;
        IProductRepository &productRepository;
        IShoppingCartDao *shoppingCartDao;
        IOrderDao *orderDao;
        IProductOrderDao *productOrderDao;
    };
}


#endif //E_COMMERCE_SHOPPINGCARTREPOSITORY_H
