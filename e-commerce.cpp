#include "CLIUserInterface.h"
#include "MapUserRepository.h"
#include "MapProductRepository.h"
#include "StorageService.h"

int main() {
    MapUserRepository userRepository = MapUserRepository();
    MapProductRepository productRepository = MapProductRepository();
    StorageService::getInstance()->setUserRepository(userRepository);
    StorageService::getInstance()->setProductRepository(productRepository);

    CLIUserInterface userInterface;

    userInterface.start();
    return 0;
}
