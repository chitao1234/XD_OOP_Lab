#include "UI/CLIUserInterface.h"
#include "DataAccess/MapUserRepository.h"
#include "DataAccess/MapProductRepository.h"
#include "Service/StorageService.h"

int main() {
    DataAccess::MapUserRepository userRepository = DataAccess::MapUserRepository();
    DataAccess::MapProductRepository productRepository = DataAccess::MapProductRepository();
    Service::StorageService::getInstance()->setUserRepository(userRepository);
    Service::StorageService::getInstance()->setProductRepository(productRepository);

    UI::CLIUserInterface userInterface;

    userInterface.start();
    return 0;
}
