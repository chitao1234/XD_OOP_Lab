//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_PRODUCTDISPLAY_H
#define E_COMMERCE_PRODUCTDISPLAY_H


#include <vector>
#include "DataType/FullProduct.h"

namespace UI {
    class ProductDisplay {
    public:
        enum DisplayType {
            BRIEF,
            BRIEF_WITH_NUMBER,
            DETAILED_WITH_STOCK,
        };

        explicit ProductDisplay(const std::vector<DataType::FullProduct> &products);

        explicit ProductDisplay(const std::vector<std::pair<DataType::FullProduct, long>> &products);

        [[nodiscard]] size_t size() const;

        std::optional<DataType::FullProduct> selectProduct(DisplayType displayType);

        std::vector<DataType::FullProduct> selectProducts(DisplayType displayType);

        std::optional<std::pair<DataType::FullProduct, long>> selectProductWithNumber(DisplayType displayType);

        std::vector<std::pair<DataType::FullProduct, long>> selectProductsWithNumber(DisplayType displayType);

        ProductDisplay searchProduct(std::string keyword);

        void setProducts(const std::vector<DataType::FullProduct> &products);

        void setProducts(const std::vector<std::pair<DataType::FullProduct, long>> &products);

        void listProducts(DisplayType displayType);

    private:
        std::vector<std::pair<DataType::FullProduct, long>> products;

        std::vector<std::pair<DataType::FullProduct, long>> interactiveSelect(DisplayType displayType, bool single);
    };
}


#endif //E_COMMERCE_PRODUCTDISPLAY_H
