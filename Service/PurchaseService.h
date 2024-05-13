//
// Created by chi on 24/05/10.
//

#ifndef E_COMMERCE_PURCHASESERVICE_H
#define E_COMMERCE_PURCHASESERVICE_H

#include "DataAccess/IShoppingCartRepository.h"
#include "DataType/Product.h"
#include "DataType/Coupon.h"
#include "PurchaseResult.h"
#include "DataAccess/ICouponRepository.h"

#include <optional>

namespace Service {

    class PurchaseService {
    public:
        explicit PurchaseService(DataAccess::IShoppingCartRepository &shoppingCartRepository,
                                 DataAccess::ICouponRepository &couponRepository);

        PurchaseResult purchase(const std::vector<std::pair<DataType::Product, long>> &productList,
                                const std::optional<DataType::Coupon> &coupon);

        PurchaseResult purchase(const DataType::Product &product);

        double calculateTotalPrice(const std::vector<std::pair<DataType::Product, long>> &productList,
                                   const std::optional<DataType::Coupon> &coupon);

    private:
        DataAccess::IShoppingCartRepository &shoppingCartRepository;
        DataAccess::ICouponRepository &couponRepository;
    };

} // Service

#endif //E_COMMERCE_PURCHASESERVICE_H
