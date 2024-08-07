//
// Created by chi on 24/05/06.
//

#include <iostream>
#include <optional>
#include <algorithm>
#include "ProductDisplay.h"
#include "Util/ErrorCheckingInputStream.h"

namespace UI {
    void ProductDisplay::listProducts(DisplayType displayType) {
        if (products.empty()) {
            std::cout << "No product" << std::endl;
            std::cout << std::endl;
            return;
        }

        int i = 1;
        // 商品展示部分，根据不同的展示方式展示不同的内容
        switch (displayType) {
            case BRIEF:
                std::cout << "Index\tName\tActualPrice" << std::endl;
                for (const auto &product: products) {
                    std::cout << i++ << "\t" << product.first.getName() << "\t" << product.first.getActualPrice()
                              << std::endl;
                }
                break;
            case BRIEF_WITH_NUMBER:
                std::cout << "Index\tName\tActualPrice\tNumber" << std::endl;
                for (const auto &product: products) {
                    std::cout << i++ << "\t" << product.first.getName() << "\t" << product.first.getActualPrice()
                              << "\t"
                              << product.second
                              << std::endl;
                }
                break;
            case DETAILED_WITH_STOCK:
                std::cout << "ID\tName\tPrice\tStock\tDiscount\tCategory" << std::endl;
                for (const auto &product: products) {
                    std::cout << product.first.getId() << "\t"
                              << product.first.getName() << "\t"
                              << product.first.getPrice() << "\t"
                              << product.second << '\t'
                              << product.first.getDiscount() << "\t"
                              << product.first.getCategory() << std::endl;
                }
                break;
        }
        std::cout << std::endl;
    }

    ProductDisplay::ProductDisplay(const std::vector<DataType::FullProduct> &products) {
        for (const DataType::FullProduct &product: products) {
            this->products.emplace_back(product, product.getRemainingStock());
        }
    }

    void ProductDisplay::setProducts(const std::vector<DataType::FullProduct> &products) {
        this->products.clear();
        for (const DataType::FullProduct &product: products) {
            this->products.emplace_back(product, product.getRemainingStock());
        }
    }

    ProductDisplay::ProductDisplay(const std::vector<std::pair<DataType::FullProduct, long>> &products)
            : products(products) {
    }

    void ProductDisplay::setProducts(const std::vector<std::pair<DataType::FullProduct, long>> &products) {
        this->products = products;
    }

    ProductDisplay ProductDisplay::searchProduct(std::string keyword) {
        // 筛选出包含关键字的产品，返回新的ProductDisplay
        std::vector<std::pair<DataType::FullProduct, long>> result;
        for (const auto &pair: products) {
            if (pair.first.getName().find(keyword) != std::string::npos) {
                result.push_back(pair);
            }
        }
        return ProductDisplay(result);
    }

    std::vector<std::pair<DataType::FullProduct, long>>
    ProductDisplay::interactiveSelect(ProductDisplay::DisplayType displayType, bool single) {
        std::vector<std::pair<DataType::FullProduct, long>> result;
        while (true) {
            listProducts(displayType);
            std::cout << "Enter Product number to select, or 's' to search and 'f' to finish: ";
            std::string input;
            Util::cinWrapper >> input;
            if (input == "f") {
                break;
            } else if (input == "s") {
                std::string search;
                std::cout << "Enter search query: ";
                Util::cinWrapper >> search;
                // 递归搜索产品，使用搜索后的列表进行交互选择，并与之前的结果合并
                auto subResult = searchProduct(search).interactiveSelect(displayType, single);
                result.reserve(result.size() + subResult.size());
                for (const auto &product: subResult) {
                    if (std::find(result.begin(), result.end(), product) != result.end()) {
                        std::cout << "DataType::FullProduct " << product.first.getName() << " already selected"
                                  << std::endl;
                        continue;
                    }
                    result.push_back(product);
                }
                if (single && !result.empty()) break;
            } else {
                long productNumber = -1;
                try {
                    productNumber = std::stol(input) - 1;
                } catch (std::invalid_argument &e) {
                }
                if (productNumber < 0 || static_cast<size_t>(productNumber) >= size()) {
                    std::cout << "Invalid DataType::FullProduct number" << std::endl;
                    continue;
                }
                result.push_back(products[productNumber]);
                if (single) break;
            }
        }
        return result;
    }

    size_t ProductDisplay::size() const {
        return products.size();
    }

    // 几种不同的交互选择方式，适应不同的需求
    std::optional<DataType::FullProduct> ProductDisplay::selectProduct(ProductDisplay::DisplayType displayType) {
        auto result = interactiveSelect(displayType, true);
        if (result.empty()) return std::nullopt;
        return {result.at(0).first};
    }

    std::optional<std::pair<DataType::FullProduct, long>>
    ProductDisplay::selectProductWithNumber(ProductDisplay::DisplayType displayType) {
        auto result = interactiveSelect(displayType, true);
        if (result.empty()) return std::nullopt;
        return {result.at(0)};
    }

    std::vector<DataType::FullProduct> ProductDisplay::selectProducts(ProductDisplay::DisplayType displayType) {
        auto selectResult = interactiveSelect(displayType, false);
        std::vector<DataType::FullProduct> result;
        result.reserve(selectResult.size());
        for (auto &pair: selectResult) {
            result.push_back(pair.first);
        }
        return result;
    }

    std::vector<std::pair<DataType::FullProduct, long>>
    ProductDisplay::selectProductsWithNumber(ProductDisplay::DisplayType displayType) {
        return interactiveSelect(displayType, false);
    }
}
