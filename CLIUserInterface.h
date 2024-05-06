#ifndef CLIUSERINTERFACE_H
#define CLIUSERINTERFACE_H

#include <vector>
#include "IUserRepository.h"
#include "ICLIState.h"
#include "IProductRepository.h"

class CLIUserInterface {
private:
    std::vector<ICLIState *> states;

public:
    explicit CLIUserInterface();

    ~CLIUserInterface();

    void start();

    IUserRepository &getUserRepository();

    IProductRepository &getProductRepository();

    void pushState(ICLIState *newState);

    void popState();

    void replaceState(ICLIState *newState);
};

#endif
