//
// Created by chi on 24/05/26.
//

#ifndef E_COMMERCE_CLISTATEORDERHISTORY_H
#define E_COMMERCE_CLISTATEORDERHISTORY_H

#include "ICLIState.h"
#include "CLIUserInterface.h"

namespace UI {
    // 订单历史界面类，用于实现用户订单历史查询功能，同时支持时间和关键字过滤
    class CLIStateOrderHistory : public ICLIState {
    public:
        explicit CLIStateOrderHistory(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;

    private:
        CLIUserInterface &userInterface;
        std::tm start, end;
        std::string keywordFilter;
    };

} // UI

#endif //E_COMMERCE_CLISTATEORDERHISTORY_H
