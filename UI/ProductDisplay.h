//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_PRODUCTDISPLAY_H
#define E_COMMERCE_PRODUCTDISPLAY_H


#include <vector>
#include "DataType/FullProduct.h"

namespace UI {
    // 产品展示类，用于展示产品列表，支持不同的展示方式，包括简要展示、简要展示带编号、详细展示带库存，支持交互选择
    // 辅助类
    class ProductDisplay {
    public:
        enum DisplayType {
            BRIEF,  // 简要展示
            BRIEF_WITH_NUMBER,  // 简要展示带编号
            DETAILED_WITH_STOCK,  // 详细展示带库存
        };

        // 传入产品列表
        explicit ProductDisplay(const std::vector<DataType::FullProduct> &products);

        // 传入产品列表和数量
        explicit ProductDisplay(const std::vector<std::pair<DataType::FullProduct, long>> &products);

        // 产品数量
        [[nodiscard]] size_t size() const;

        // 交互选择产品
        std::optional<DataType::FullProduct> selectProduct(DisplayType displayType);

        // 交互选择多个产品
        std::vector<DataType::FullProduct> selectProducts(DisplayType displayType);

        // 交互选择产品和数量
        std::optional<std::pair<DataType::FullProduct, long>> selectProductWithNumber(DisplayType displayType);

        // 交互选择多个产品和数量
        std::vector<std::pair<DataType::FullProduct, long>> selectProductsWithNumber(DisplayType displayType);

        // 搜索产品
        ProductDisplay searchProduct(std::string keyword);

        // 设置产品列表
        void setProducts(const std::vector<DataType::FullProduct> &products);

        // 设置产品列表和数量
        void setProducts(const std::vector<std::pair<DataType::FullProduct, long>> &products);

        void listProducts(DisplayType displayType);

    private:
        std::vector<std::pair<DataType::FullProduct, long>> products;

        // 交互选择的实现
        std::vector<std::pair<DataType::FullProduct, long>> interactiveSelect(DisplayType displayType, bool single);
    };
}


#endif //E_COMMERCE_PRODUCTDISPLAY_H
