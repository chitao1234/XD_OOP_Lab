#include "CLIUserInterface.h"
#include "CLIStateMainMenu.h"

namespace UI {
    CLIUserInterface::CLIUserInterface() {
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
        delete state;
        states.pop_back();
    }

    void CLIUserInterface::replaceState(ICLIState *newState) {
        popState();
        pushState(newState);
    }
}
