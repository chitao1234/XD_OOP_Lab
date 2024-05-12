//
// Created by chi on 24/05/10.
//

#include "PurchaseService.h"
#include "StorageService.h"
#include "DataAccess/IProductRepository.h"

namespace Service {

    PurchaseService::PurchaseService(DataAccess::IShoppingCartRepository &shoppingCartRepository)
            : shoppingCartRepository(shoppingCartRepository) {
    }


    PurchaseResult PurchaseService::purchase(const std::vector<std::pair<DataType::Product, long>> &productList) {
        DataAccess::IProductRepository &productRepository = StorageService::getInstance()->getProductRepository();
        for (const auto &product: productList) {
            // Check is stock is enough
            if (productRepository.getProduct(product.first.getId()).value().getRemainingStock() < product.second) {
                return PurchaseResult::stockNotEnough(product.first.getName());
            }
        }

        for (const auto &product: productList) {
            shoppingCartRepository.removeProduct(product.first.getId());
            DataType::Product newProduct = productRepository.getProduct(product.first.getId()).value();
            newProduct.setRemainingStock(newProduct.getRemainingStock() - product.second);
            productRepository.updateProduct(newProduct);
        }

        return PurchaseResult::success();
    }

    double PurchaseService::calculateTotalPrice(const std::vector<std::pair<DataType::Product, long>> &productList) {
        double totalPrice = 0;
        for (const auto &product: productList) {
            totalPrice += product.first.getPrice() * static_cast<double>(product.second);
        }
        return totalPrice;
    }
} // Service