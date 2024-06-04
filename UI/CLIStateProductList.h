//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_CLISTATEPRODUCTLIST_H
#define E_COMMERCE_CLISTATEPRODUCTLIST_H

#include <vector>
#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "DataType/Product.h"
#include "ProductDisplay.h"

namespace UI {
    // 商品列表界面类，用于显示商品列表，支持查看商品详情，支持筛选
    // 使用了ProductDisplay类来显示商品列表和筛选
    class CLIStateProductList : public ICLIState {
    public:
        CLIStateProductList(CLIUserInterface &userInterface, const std::vector<DataType::FullProduct> &products);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        ProductDisplay productDisplay;
    };
}


#endif //E_COMMERCE_CLISTATEPRODUCTLIST_H
