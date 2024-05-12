//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_PRODUCTDISPLAY_H
#define E_COMMERCE_PRODUCTDISPLAY_H


#include <vector>
#include "../DataType/Product.h"

namespace UI {
    class ProductDisplay {
    public:
        enum DisplayType {
            BRIEF,
            BRIEF_WITH_NUMBER,
            DETAILED_WITH_STOCK,
        };

        explicit ProductDisplay(const std::vector<DataType::Product> &products);

        explicit ProductDisplay(const std::vector<std::pair<DataType::Product, long>> &products);

        [[nodiscard]] size_t size() const;

        std::optional<DataType::Product> selectProduct(DisplayType displayType);

        std::vector<DataType::Product> selectProducts(DisplayType displayType);

        std::optional<std::pair<DataType::Product, long>> selectProductWithNumber(DisplayType displayType);

        std::vector<std::pair<DataType::Product, long>> selectProductsWithNumber(DisplayType displayType);

        ProductDisplay searchProduct(std::string keyword);

        void setProducts(const std::vector<DataType::Product> &products);

        void setProducts(const std::vector<std::pair<DataType::Product, long>> &products);

        void listProducts(DisplayType displayType);

    private:
        std::vector<std::pair<DataType::Product, long>> products;

        std::vector<std::pair<DataType::Product, long>> interactiveSelect(DisplayType displayType, bool single);
    };
}


#endif //E_COMMERCE_PRODUCTDISPLAY_H