//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_PURCHASERESULT_H
#define E_COMMERCE_PURCHASERESULT_H

#include <string>
#include <cstdint>

namespace Service {
    struct PurchaseResult {
        enum class ErrorType {
            STOCK_NOT_ENOUGH,
            UNKNOWN
        };

        bool isError;
        ErrorType errorType;
        std::string message;

        static PurchaseResult success();

        static PurchaseResult stockNotEnough(const std::string &productName);

        explicit operator bool() const {
            return !isError;
        }
    };
}


#endif //E_COMMERCE_PURCHASERESULT_H
