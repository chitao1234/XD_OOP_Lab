#include "UI/CLIUserInterface.h"
#include "DataAccess/MapUserRepository.h"
#include "DataAccess/MapProductRepository.h"
#include "Service/StorageService.h"
#include "DataAccess/CouponRepository.h"
#include "DataAccess/MapDaoFactory.h"
#include "DataAccess/MapRepositoryFactory.h"

int main() {
    DataAccess::MapDaoFactory daoFactory = DataAccess::MapDaoFactory();
    DataAccess::MapRepositoryFactory repositoryFactory = DataAccess::MapRepositoryFactory(daoFactory);
    Service::StorageService *storageService = Service::StorageService::getInstance();
    storageService->setRepositoryFactory(&repositoryFactory);

    UI::CLIUserInterface userInterface;

    userInterface.start();
    return 0;
}
