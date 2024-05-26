//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_IPRODUCTORDERDAO_H
#define E_COMMERCE_IPRODUCTORDERDAO_H

#include <string>
#include <cinttypes>

namespace DataAccess {
    class IProductOrderDao {
    public:
        virtual ~IProductOrderDao() = default;

        virtual void addProductToOrder(uint64_t orderId, uint64_t productId, long quantity) = 0;

        virtual void removeProductFromOrder(uint64_t orderId, uint64_t productId) = 0;

        virtual std::vector<std::pair<uint64_t, long>> getProducts(uint64_t orderId) = 0;

        virtual void updateProductQuantity(uint64_t orderId, uint64_t productId, long quantity) = 0;

        virtual void clearOrder(uint64_t orderId) = 0;

        virtual void save() = 0;

        virtual bool load() = 0;
    };
}

#endif //E_COMMERCE_IPRODUCTORDERDAO_H
