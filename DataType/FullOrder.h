//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_FULLORDER_H
#define E_COMMERCE_FULLORDER_H

#include "Order.h"
#include "FullProduct.h"
#include <vector>

namespace DataType {
    // 完整订单类，包含订单信息和商品信息
    class FullOrder : public Order {
    public:
        FullOrder(Order order, std::vector<std::pair<FullProduct, long>> products);

        // 获取订单商品列表
        [[nodiscard]] std::vector<std::pair<FullProduct, long>> getProducts() const;

    private:
        std::vector<std::pair<FullProduct, long>> productList;
    };

} // DataType

#endif //E_COMMERCE_FULLORDER_H
