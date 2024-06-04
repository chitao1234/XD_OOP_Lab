//
// Created by chi on 24/04/29.
//

#ifndef E_COMMERCE_CLISTATEPRODUCTDETAIL_H
#define E_COMMERCE_CLISTATEPRODUCTDETAIL_H

#include "ICLIState.h"
#include "DataType/Product.h"
#include "CLIUserInterface.h"

namespace UI {
    // 商品详情界面类，用于显示商品详情，支持加入购物车和直接购买
    class CLIStateProductDetail : public ICLIState {
    public:
        CLIStateProductDetail(CLIUserInterface &userInterface, DataType::FullProduct product);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        DataType::FullProduct product;
    };
}


#endif //E_COMMERCE_CLISTATEPRODUCTDETAIL_H
