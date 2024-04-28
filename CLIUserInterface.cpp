#include "CLIUserInterface.h"
#include "CLIStateMainMenu.h"

CLIUserInterface::CLIUserInterface(IUserRepository &userRepository)
        : userRepository(userRepository) {
    state = new CLIStateMainMenu(*this);
}

CLIUserInterface::~CLIUserInterface() {
    delete state;
}

void CLIUserInterface::start() {
    while (true) {
        state->displayMenu();
        if (state->handleUserInput()) {
            break;
        }
    }
}

IUserRepository &CLIUserInterface::getUserRepository() {
    return userRepository;
}

void CLIUserInterface::setState(ICLIState *newState) {
    state = newState;
}
