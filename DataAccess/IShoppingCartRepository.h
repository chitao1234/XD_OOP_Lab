//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_ISHOPPINGCARTREPOSITORY_H
#define E_COMMERCE_ISHOPPINGCARTREPOSITORY_H

#include <vector>
#include "../DataType/Product.h"


namespace DataAccess {
    class IShoppingCartRepository {
    public:
        virtual ~IShoppingCartRepository() = default;

        virtual std::vector<std::pair<DataType::Product, long>> listProducts() = 0;

        virtual void addProduct(uint64_t productId, long quantity) = 0;

        virtual void removeProduct(uint64_t productId) = 0;

        virtual void updateProductQuantity(uint64_t productId, long quantity) = 0;

        virtual void clearCart() = 0;
    };
}


#endif //E_COMMERCE_ISHOPPINGCARTREPOSITORY_H
