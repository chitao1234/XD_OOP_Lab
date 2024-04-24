#include "CLIUserInterface.h"
#include "MapUserRepository.h"

int main() {
    MapUserRepository userRepository = MapUserRepository();
    CLIUserInterface userInterface(userRepository);

    bool exit = false;
    while (!exit) {
        userInterface.displayMenu();
        exit = userInterface.handleUserInput();
    }
}
