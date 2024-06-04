//
// Created by chi on 24/05/01.
//

#ifndef E_COMMERCE_CLISTATEPRODUCTMAINTENANCE_H
#define E_COMMERCE_CLISTATEPRODUCTMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "ProductDisplay.h"

namespace UI {
    // 商品维护界面类，用于添加、修改、删除商品和处理商品折扣活动
    class CLIStateProductMaintenance : public ICLIState {
    public:
        explicit CLIStateProductMaintenance(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        ProductDisplay productDisplay;
    };
}


#endif //E_COMMERCE_CLISTATEPRODUCTMAINTENANCE_H
