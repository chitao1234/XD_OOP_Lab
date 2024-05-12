//
// Created by chi on 24/05/10.
//

#ifndef E_COMMERCE_PURCHASESERVICE_H
#define E_COMMERCE_PURCHASESERVICE_H

#include "DataAccess/IShoppingCartRepository.h"
#include "DataType/Product.h"
#include "PurchaseResult.h"

namespace Service {

    class PurchaseService {
    public:
        explicit PurchaseService(DataAccess::IShoppingCartRepository &shoppingCartRepository);

        PurchaseResult purchase(const std::vector<std::pair<DataType::Product, long>>& productList);

        double calculateTotalPrice(const std::vector<std::pair<DataType::Product, long>>& productList);
    private:
        DataAccess::IShoppingCartRepository &shoppingCartRepository;
    };

} // Service

#endif //E_COMMERCE_PURCHASESERVICE_H
