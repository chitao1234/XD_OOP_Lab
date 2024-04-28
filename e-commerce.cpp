#include "CLIUserInterface.h"
#include "MapUserRepository.h"

int main() {
    MapUserRepository userRepository = MapUserRepository();
    CLIUserInterface userInterface(userRepository);

    userInterface.start();
    return 0;
}
