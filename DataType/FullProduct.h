//
// Created by chi on 24/05/27.
//

#ifndef E_COMMERCE_FULLPRODUCT_H
#define E_COMMERCE_FULLPRODUCT_H

#include "Product.h"

namespace DataType {
    // 完整商品类，包含商品信息和商品类别名称
    class FullProduct : public Product {
    public:
        FullProduct(Product product, std::string category);

        [[nodiscard]] std::string getCategory() const;

        void setCategory(std::string category);

    private:
        std::string category;
    };

} // DataType

#endif //E_COMMERCE_FULLPRODUCT_H
