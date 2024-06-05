//
// Created by chi on 24/05/10.
//

#include "PurchaseService.h"
#include "StorageService.h"
#include "SessionManager.h"
#include "DataAccess/IProductRepository.h"

namespace Service {
    PurchaseService::PurchaseService(DataAccess::ICartOrderRepository &cartOrderRepository,
                                     DataAccess::ICouponRepository &couponRepository)
            : cartOrderRepository(cartOrderRepository), couponRepository(couponRepository) {
    }


    PurchaseResult PurchaseService::purchase(const std::vector<std::pair<DataType::FullProduct, long>> &productList,
                                             const std::optional<DataType::Coupon> &coupon) {
        // 先检测库存是否足够
        DataAccess::IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
        for (const auto &product: productList) {
            // Check is stock is enough
            if (productRepository.getProduct(product.first.getId()).value().getRemainingStock() < product.second) {
                return PurchaseResult::stockNotEnough(product.first.getName());
            }
        }

        // 开始进行购买，先将订单加入订单表
        cartOrderRepository.addOrder(productList, calculateTotalPrice(productList, coupon));

        // 更新库存，添加商品到订单表，删除购物车中的商品
        for (const auto &product: productList) {
            cartOrderRepository.removeProduct(product.first.getId());
            DataType::FullProduct newProduct = productRepository.getProduct(product.first.getId()).value();
            newProduct.setRemainingStock(newProduct.getRemainingStock() - product.second);
            productRepository.updateProduct(newProduct);
        }

        // 如果使用了优惠券，则将优惠券从用户中删除
        if (coupon.has_value()) {
            couponRepository.removeCouponFromUser(
                    SessionManager::getInstance()->getCurrentUser().value().getUsername(),
                    coupon.value().getId()
            );
        }

        return PurchaseResult::success();
    }

    double PurchaseService::calculateTotalPrice(const std::vector<std::pair<DataType::FullProduct, long>> &productList,
                                                const std::optional<DataType::Coupon> &coupon) {
        double totalPrice = 0;
        for (const auto &product: productList) {
            totalPrice += product.first.getActualPrice() * static_cast<double>(product.second);
        }
        // 如果有优惠券，则应用优惠券
        if (coupon.has_value()) {
            totalPrice = coupon.value().apply(totalPrice);
        }
        return totalPrice;
    }

    // 购买单个商品，只需要处理库存问题
    PurchaseResult PurchaseService::purchase(const DataType::FullProduct &product) {
        return purchase({{product, 1}}, std::nullopt);
    }
} // Service