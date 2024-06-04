//
// Created by chi on 24/05/13.
//

#ifndef E_COMMERCE_CLISTATECOUPONMAINTENANCE_H
#define E_COMMERCE_CLISTATECOUPONMAINTENANCE_H

#include "ICLIState.h"
#include "CLIUserInterface.h"
#include "DataType/Coupon.h"

namespace UI {
    // 优惠券维护界面类，用于实现优惠券维护功能
    class CLIStateCouponMaintenance : public ICLIState {
    public:
        explicit CLIStateCouponMaintenance(CLIUserInterface &userInterface);

        void displayMenu() override;

        void handleUserInput() override;
    private:
        // 显示优惠券列表
        void displayCouponList(const std::vector<DataType::Coupon> &couponList);

        void displayCouponList();

        void displayUserCouponList(const std::string &username);

        CLIUserInterface &userInterface;
    };

} // UI

#endif //E_COMMERCE_CLISTATECOUPONMAINTENANCE_H
