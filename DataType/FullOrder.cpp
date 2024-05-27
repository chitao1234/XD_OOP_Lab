//
// Created by chi on 24/05/26.
//

#include "FullOrder.h"


namespace DataType {
    FullOrder::FullOrder(Order order, std::vector<std::pair<FullProduct, long>> products)
            : Order(std::move(order)),
              productList(std::move(products)) {}

    std::vector<std::pair<FullProduct, long>> FullOrder::getProducts() const {
        return productList;
    }

} // DataType