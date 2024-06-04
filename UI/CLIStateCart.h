//
// Created by chi on 24/05/06.
//

#ifndef E_COMMERCE_CLISTATECART_H
#define E_COMMERCE_CLISTATECART_H

#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "ProductDisplay.h"
#include "DataType/Coupon.h"

namespace UI {
    // 购物车界面类，用于实现购物车功能
    class CLIStateCart : public ICLIState {
    public:
        explicit CLIStateCart(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;

        // 使用产品展示类，用于显示产品信息
        ProductDisplay productDisplay;

        std::vector<std::pair<DataType::FullProduct, long>> selected;

        std::optional<DataType::Coupon> displayCoupons(bool select);
    };
}


#endif //E_COMMERCE_CLISTATECART_H
