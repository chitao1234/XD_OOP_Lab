//
// Created by chi on 24/05/27.
//

#include "FullProduct.h"

namespace DataType {
    FullProduct::FullProduct(Product product, std::string category)
            : Product(std::move(product)), category(std::move(category)) {}

    std::string FullProduct::getCategory() const {
        return category;
    }

} // DataType