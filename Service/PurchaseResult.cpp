//
// Created by chi on 24/05/12.
//

#include "PurchaseResult.h"

namespace Service {
    PurchaseResult::ErrorType PurchaseResult::getErrorType() const {
        return errorType;
    }

    PurchaseResult PurchaseResult::success() {
        PurchaseResult result;
        result.isError = false;
        result.errorType = ErrorType::UNKNOWN;
        result.message = "";
        return result;
    }

    PurchaseResult PurchaseResult::stockNotEnough(const std::string &productName) {
        PurchaseResult result;
        result.isError = true;
        result.errorType = ErrorType::STOCK_NOT_ENOUGH;
        result.message = "Stock of " + productName + " is not enough";
        return result;
    }

    std::string PurchaseResult::getMessage() const {
        return message;
    }

    PurchaseResult::operator bool() const {
        return !isError;
    }
}