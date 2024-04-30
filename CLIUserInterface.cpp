#include "CLIUserInterface.h"
#include "CLIStateMainMenu.h"

CLIUserInterface::CLIUserInterface(IUserRepository &userRepository, IProductRepository &productRepository)
        : userRepository(userRepository), productRepository(productRepository) {
    pushState(new CLIStateMainMenu(*this));
}

CLIUserInterface::~CLIUserInterface() {
    for (std::vector<ICLIState *>::iterator it = states.begin(); it != states.end(); ++it) {
        delete *it;
    }
}

void CLIUserInterface::start() {
    while (!states.empty()) {
        states.back()->displayMenu();
        states.back()->handleUserInput();
    }
}

IUserRepository &CLIUserInterface::getUserRepository() {
    return userRepository;
}

void CLIUserInterface::pushState(ICLIState *newState) {
    states.push_back(newState);
}

void CLIUserInterface::popState() {
    ICLIState *state = states.back();
    delete state;
    states.pop_back();
}

IProductRepository &CLIUserInterface::getProductRepository() {
    return productRepository;
}
