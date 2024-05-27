//
// Created by chi on 24/05/27.
//

#ifndef E_COMMERCE_FULLPRODUCT_H
#define E_COMMERCE_FULLPRODUCT_H

#include "Product.h"

namespace DataType {

    class FullProduct : public Product {
    public:
        FullProduct(Product product, std::string category);

        [[nodiscard]] std::string getCategory() const;

    private:
        std::string category;
    };

} // DataType

#endif //E_COMMERCE_FULLPRODUCT_H
