//
// Created by chi on 24/05/12.
//

#include "PurchaseResult.h"

namespace Service {
    PurchaseResult PurchaseResult::success() {
        return {false, PurchaseResult::ErrorType::UNKNOWN, ""};
    }

    PurchaseResult PurchaseResult::stockNotEnough(const std::string& productName) {
        return {true, PurchaseResult::ErrorType::STOCK_NOT_ENOUGH, "Stock of " + productName + " is not enough"};
    }
}