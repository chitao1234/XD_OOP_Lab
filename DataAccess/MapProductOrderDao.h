//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_MAPPRODUCTORDERDAO_H
#define E_COMMERCE_MAPPRODUCTORDERDAO_H

#include <map>
#include <vector>
#include "IProductOrderDao.h"

namespace DataAccess {

    class MapProductOrderDao : public IProductOrderDao {
    public:
        explicit MapProductOrderDao(std::string filename);

        ~MapProductOrderDao() override;

        void addProductToOrder(uint64_t orderId, uint64_t productId, long quantity) override;

        void removeProductFromOrder(uint64_t orderId, uint64_t productId) override;

        std::vector<std::pair<uint64_t, long>> getProducts(uint64_t orderId) override;

        void updateProductQuantity(uint64_t orderId, uint64_t productId, long quantity) override;

        void clearOrder(uint64_t orderId) override;

        void save() override;

        bool load() override;

    private:
        std::string filename;
        std::map<uint64_t, std::vector<std::pair<uint64_t, long>>> orderProductMap;
    };

} // DataAccess

#endif //E_COMMERCE_MAPPRODUCTORDERDAO_H
