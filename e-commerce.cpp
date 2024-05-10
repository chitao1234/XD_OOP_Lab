#include "UI/CLIUserInterface.h"
#include "DataAccess/MapUserRepository.h"
#include "DataAccess/MapProductRepository.h"
#include "Service/StorageService.h"

int main() {
    MapUserRepository userRepository = MapUserRepository();
    MapProductRepository productRepository = MapProductRepository();
    StorageService::getInstance()->setUserRepository(userRepository);
    StorageService::getInstance()->setProductRepository(productRepository);

    CLIUserInterface userInterface;

    userInterface.start();
    return 0;
}
