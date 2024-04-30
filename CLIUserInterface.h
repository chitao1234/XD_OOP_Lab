#ifndef CLIUSERINTERFACE_H
#define CLIUSERINTERFACE_H

#include <vector>
#include "IUserRepository.h"
#include "ICLIState.h"
#include "IProductRepository.h"

class CLIUserInterface {
private:
    IUserRepository &userRepository;
    IProductRepository &productRepository;
    std::vector<ICLIState *> states;

public:
    explicit CLIUserInterface(IUserRepository &userRepository, IProductRepository &productRepository);

    ~CLIUserInterface();

    void start();

    IUserRepository &getUserRepository();

    IProductRepository &getProductRepository();

    void pushState(ICLIState *newState);

    void popState();
};

#endif
