#ifndef CLIUSERINTERFACE_H
#define CLIUSERINTERFACE_H

#include "IUserRepository.h"
#include "ICLIState.h"

class CLIUserInterface {
private:
    IUserRepository &userRepository;
    ICLIState *state;

public:
    explicit CLIUserInterface(IUserRepository &userRepository);

    ~CLIUserInterface();

    void start();

    IUserRepository &getUserRepository();

    void setState(ICLIState *state);
};

#endif
