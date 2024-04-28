#include "CLIUserInterface.h"
#include "CLIStateMainMenu.h"

CLIUserInterface::CLIUserInterface(IUserRepository &userRepository)
        : userRepository(userRepository) {
    state = new CLIStateMainMenu(*this);
}

CLIUserInterface::~CLIUserInterface() {
    delete state;
}

void CLIUserInterface::displayMenu() {
    state->displayMenu();
}

bool CLIUserInterface::handleUserInput() {
    return state->handleUserInput();
}

IUserRepository &CLIUserInterface::getUserRepository() {
    return userRepository;
}

void CLIUserInterface::setState(ICLIState *newState) {
    state = newState;
}
