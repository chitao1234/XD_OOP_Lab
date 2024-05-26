//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_FULLORDER_H
#define E_COMMERCE_FULLORDER_H

#include "Order.h"
#include "Product.h"
#include <vector>

namespace DataType {

    class FullOrder : public Order {
    public:
        FullOrder(Order order, std::vector<std::pair<Product, long>> products);

        [[nodiscard]] std::vector<std::pair<Product, long>> getProducts() const;

    private:
        std::vector<std::pair<Product, long>> productList;
    };

} // DataType

#endif //E_COMMERCE_FULLORDER_H
