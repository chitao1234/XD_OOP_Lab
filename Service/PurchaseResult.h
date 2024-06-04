//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_PURCHASERESULT_H
#define E_COMMERCE_PURCHASERESULT_H

#include <string>
#include <cstdint>

namespace Service {
    // 购买结果类，用于表示购买操作的结果
    class PurchaseResult {
    public:
        // 使用类中的枚举类型表示错误类型
        enum class ErrorType {
            STOCK_NOT_ENOUGH,  // 库存不足
            UNKNOWN  // 未知错误
        };

        // 静态函数，用于创建成功的购买结果
        static PurchaseResult success();

        // 静态函数，用于创建库存不足的购买结果
        static PurchaseResult stockNotEnough(const std::string &productName);

        [[nodiscard]] ErrorType getErrorType() const;

        [[nodiscard]] std::string getMessage() const;

        // 重载 bool 类型转换运算符，方便判断是否出错
        explicit operator bool() const;

    private:
        bool isError;
        ErrorType errorType;
        std::string message;
    };
}


#endif //E_COMMERCE_PURCHASERESULT_H
