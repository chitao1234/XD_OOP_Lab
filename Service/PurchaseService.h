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
    // 购买服务类，用于处理购买商品的相关操作
    class PurchaseService {
    public:
        explicit PurchaseService(DataAccess::ICartOrderRepository &cartOrderRepository,
                                 DataAccess::ICouponRepository &couponRepository);

        // 购买多个商品，并且可能使用优惠券
        PurchaseResult purchase(const std::vector<std::pair<DataType::FullProduct, long>> &productList,
                                const std::optional<DataType::Coupon> &coupon);

        // 购买单个商品
        PurchaseResult purchase(const DataType::FullProduct &product);

        // 计算购买商品的总价
        double calculateTotalPrice(const std::vector<std::pair<DataType::FullProduct, long>> &productList,
                                   const std::optional<DataType::Coupon> &coupon);

    private:
        DataAccess::ICartOrderRepository &cartOrderRepository;
        DataAccess::ICouponRepository &couponRepository;
    };

} // Service

#endif //E_COMMERCE_PURCHASESERVICE_H
