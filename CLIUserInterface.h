#ifndef CLIUSERINTERFACE_H
#define CLIUSERINTERFACE_H

#include <vector>
#include "IUserRepository.h"
#include "ICLIState.h"

class CLIUserInterface {
private:
    IUserRepository &userRepository;
    std::vector<ICLIState *> states;

public:
    explicit CLIUserInterface(IUserRepository &userRepository);

    ~CLIUserInterface();

    void start();

    IUserRepository &getUserRepository();

    void pushState(ICLIState *newState);

    void popState();
};

#endif
