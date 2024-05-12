//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_ISHOPPINGCARTDAO_H
#define E_COMMERCE_ISHOPPINGCARTDAO_H

#include <cstdint>
#include "../DataType/Product.h"

namespace DataAccess {
    class IShoppingCartDao {
    public:
        virtual ~IShoppingCartDao() = default;

        virtual std::vector<std::pair<uint64_t, long>> listProductIds(std::string username) = 0;

        virtual long getProductQuantity(std::string username, uint64_t productId) = 0;

        virtual void removeProduct(std::string username, uint64_t productId) = 0;

        virtual void updateProductQuantity(std::string username, uint64_t productId, long quantity) = 0;

        virtual void clearCart(std::string username) = 0;

        virtual void save() = 0;

        virtual bool load() = 0;
    };
}


#endif //E_COMMERCE_ISHOPPINGCARTDAO_H
