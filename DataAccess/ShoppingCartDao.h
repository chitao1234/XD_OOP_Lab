//
// Created by chi on 24/05/05.
//

#ifndef E_COMMERCE_SHOPPINGCARTDAO_H
#define E_COMMERCE_SHOPPINGCARTDAO_H

#include <set>
#include <map>
#include <vector>
#include "IShoppingCartDao.h"

namespace DataAccess {
    class ShoppingCartDao : public IShoppingCartDao {
    public:
        explicit ShoppingCartDao(std::string filename);

        ~ShoppingCartDao() override;

        std::vector<std::pair<uint64_t, long>> listProductIds(std::string username) override;

        long getProductQuantity(std::string username, uint64_t productId) override;

        void removeProduct(std::string username, uint64_t productId) override;

        void updateProductQuantity(std::string username, uint64_t productId, long quantity) override;

        void clearCart(std::string username) override;

        void save() override;

        bool load() override;

    private:
        std::string filename;
        std::map<std::string, std::vector<std::pair<uint64_t, long>>> carts;
    };
}

#endif //E_COMMERCE_SHOPPINGCARTDAO_H
