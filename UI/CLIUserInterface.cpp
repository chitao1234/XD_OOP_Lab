#include "CLIUserInterface.h"
#include "CLIStateMainMenu.h"

namespace UI {
    CLIUserInterface::CLIUserInterface() {
        // 初始化时，将主菜单界面压入状态栈
        pushState(new CLIStateMainMenu(*this));
    }

    CLIUserInterface::~CLIUserInterface() {
        for (auto &state: states) {
            delete state;
        }
    }

    void CLIUserInterface::start() {
        while (!states.empty()) {
            states.back()->displayMenu();
            states.back()->handleUserInput();
        }
    }

    void CLIUserInterface::pushState(ICLIState *newState) {
        states.push_back(newState);
    }

    void CLIUserInterface::popState() {
        ICLIState *state = states.back();
        // 做好状态的清理工作
        delete state;
        states.pop_back();
    }

    void CLIUserInterface::replaceState(ICLIState *newState) {
        popState();
        pushState(newState);
    }
}
