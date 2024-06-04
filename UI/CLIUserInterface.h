#ifndef CLIUSERINTERFACE_H
#define CLIUSERINTERFACE_H

#include <vector>
#include "DataAccess/IUserRepository.h"
#include "ICLIState.h"
#include "DataAccess/IProductRepository.h"

namespace UI {
    // 命令行用户界面类，只有该类与外界交互
    class CLIUserInterface {
    private:
        // 状态栈，实现界面状态的切换，导航，返回，栈顶为当前状态
        std::vector<ICLIState *> states;

    public:
        CLIUserInterface();

        ~CLIUserInterface();

        void start();

        // 用于界面状态的添加
        void pushState(ICLIState *newState);

        // 用于界面状态的返回
        void popState();

        // 用于界面状态的替换
        void replaceState(ICLIState *newState);
    };
}

#endif
