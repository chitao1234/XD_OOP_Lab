#ifndef CLIUSERINTERFACE_H
#define CLIUSERINTERFACE_H

#include <vector>
#include "DataAccess/IUserRepository.h"
#include "ICLIState.h"
#include "DataAccess/IProductRepository.h"

namespace UI {
    class CLIUserInterface {
    private:
        std::vector<ICLIState *> states;

    public:
        explicit CLIUserInterface();

        ~CLIUserInterface();

        void start();

        void pushState(ICLIState *newState);

        void popState();

        void replaceState(ICLIState *newState);
    };
}

#endif
