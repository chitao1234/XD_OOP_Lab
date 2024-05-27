//
// Created by chi on 24/05/10.
//

#ifndef E_COMMERCE_PURCHASESERVICE_H
#define E_COMMERCE_PURCHASESERVICE_H

#include "DataAccess/ICartOrderRepository.h"
#include "DataType/Product.h"
#include "DataType/Coupon.h"
#include "PurchaseResult.h"
#include "DataAccess/ICouponRepository.h"

#include <optional>

namespace Service {

    class PurchaseService {
    public:
        explicit PurchaseService(DataAccess::ICartOrderRepository &cartOrderRepository,
                                 DataAccess::ICouponRepository &couponRepository);

        PurchaseResult purchase(const std::vector<std::pair<DataType::FullProduct, long>> &productList,
                                const std::optional<DataType::Coupon> &coupon);

        PurchaseResult purchase(const DataType::FullProduct &product);

        double calculateTotalPrice(const std::vector<std::pair<DataType::FullProduct, long>> &productList,
                                   const std::optional<DataType::Coupon> &coupon);

    private:
        DataAccess::ICartOrderRepository &cartOrderRepository;
        DataAccess::ICouponRepository &couponRepository;
    };

} // Service

#endif //E_COMMERCE_PURCHASESERVICE_H
