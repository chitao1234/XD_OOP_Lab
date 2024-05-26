//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_PURCHASERESULT_H
#define E_COMMERCE_PURCHASERESULT_H

#include <string>
#include <cstdint>

namespace Service {
    class PurchaseResult {
    public:
        enum class ErrorType {
            STOCK_NOT_ENOUGH,
            UNKNOWN
        };

        static PurchaseResult success();

        static PurchaseResult stockNotEnough(const std::string &productName);

        [[nodiscard]] ErrorType getErrorType() const;

        [[nodiscard]] std::string getMessage() const;

        explicit operator bool() const {
            return !isError;
        }
    private:
        bool isError;
        ErrorType errorType;
        std::string message;
    };
}


#endif //E_COMMERCE_PURCHASERESULT_H
