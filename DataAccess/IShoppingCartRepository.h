//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_ISHOPPINGCARTREPOSITORY_H
#define E_COMMERCE_ISHOPPINGCARTREPOSITORY_H

#include <vector>
#include <chrono>
#include <optional>
#include <string>
#include "DataType/Product.h"
#include "DataType/FullOrder.h"


namespace DataAccess {
    class IShoppingCartRepository {
    public:
        virtual ~IShoppingCartRepository() = default;

        virtual std::vector<std::pair<DataType::Product, long>> listProducts() = 0;

        virtual void addProduct(uint64_t productId, long quantity) = 0;

        virtual void removeProduct(uint64_t productId) = 0;

        virtual void updateProductQuantity(uint64_t productId, long quantity) = 0;

        virtual void clearCart() = 0;

        virtual bool exportToFile(std::string filename) = 0;

        virtual bool importFromFile(std::string filename) = 0;

        virtual void addOrder(std::vector<std::pair<DataType::Product, long>> products, double price) = 0;

        virtual std::vector<DataType::FullOrder> filterOrders(
                std::optional<std::string> keyword,
                std::optional<std::chrono::system_clock::time_point> start,
                std::optional<std::chrono::system_clock::time_point> end) = 0;
    };
}


#endif //E_COMMERCE_ISHOPPINGCARTREPOSITORY_H
