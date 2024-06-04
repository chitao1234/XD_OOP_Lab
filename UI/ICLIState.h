//
// Created by chi on 24/04/24.
//

#ifndef E_COMMERCE_ICLISTATE_H
#define E_COMMERCE_ICLISTATE_H


namespace UI {
    // 命令行界面状态接口，用于实现页面功能，实现状态模式
    // 通过继承该接口，实现不同的页面功能，用户界面类通过该接口调用页面功能
    class ICLIState {
    public:
        // 接口需要虚析构函数
        virtual ~ICLIState() = default;

        // 显示菜单
        virtual void displayMenu() = 0;

        // 处理用户输入
        virtual void handleUserInput() = 0;
    };
}


#endif //E_COMMERCE_ICLISTATE_H
