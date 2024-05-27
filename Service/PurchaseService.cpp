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
        DataAccess::IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
        for (const auto &product: productList) {
            // Check is stock is enough
            if (productRepository.getProduct(product.first.getId()).value().getRemainingStock() < product.second) {
                return PurchaseResult::stockNotEnough(product.first.getName());
            }
        }

        // now we can proceed with the purchase
        cartOrderRepository.addOrder(productList, calculateTotalPrice(productList, coupon));

        for (const auto &product: productList) {
            cartOrderRepository.removeProduct(product.first.getId());
            DataType::FullProduct newProduct = productRepository.getProduct(product.first.getId()).value();
            newProduct.setRemainingStock(newProduct.getRemainingStock() - product.second);
            productRepository.updateProduct(newProduct);
        }

        if (coupon.has_value()) {
            couponRepository.removeCouponFromUser(SessionManager::getInstance()->getCurrentUser().value().getUsername(),
                                                  coupon.value().getId());
        }

        return PurchaseResult::success();
    }

    double PurchaseService::calculateTotalPrice(const std::vector<std::pair<DataType::FullProduct, long>> &productList,
                                                const std::optional<DataType::Coupon> &coupon) {
        double totalPrice = 0;
        for (const auto &product: productList) {
            totalPrice += product.first.getActualPrice() * static_cast<double>(product.second);
        }
        if (coupon.has_value()) {
            totalPrice = coupon.value().apply(totalPrice);
        }
        return totalPrice;
    }

    PurchaseResult PurchaseService::purchase(const DataType::FullProduct &product) {
        DataAccess::IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
        cartOrderRepository.removeProduct(product.getId());
        DataType::FullProduct newProduct = productRepository.getProduct(product.getId()).value();
        newProduct.setRemainingStock(newProduct.getRemainingStock() - 1);
        productRepository.updateProduct(newProduct);
        return PurchaseResult::success();
    }
} // Service