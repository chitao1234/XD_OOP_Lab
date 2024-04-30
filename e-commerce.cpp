#include "CLIUserInterface.h"
#include "MapUserRepository.h"
#include "MapProductRepository.h"

int main() {
    MapUserRepository userRepository = MapUserRepository();
    MapProductRepository productRepository = MapProductRepository();
    CLIUserInterface userInterface(userRepository, productRepository);

    userInterface.start();
    return 0;
}
