#include "UI/CLIUserInterface.h"
#include "DataAccess/UserRepository.h"
#include "DataAccess/ProductRepository.h"
#include "Service/StorageService.h"
#include "DataAccess/CouponRepository.h"
#include "DataAccess/MapDaoFactory.h"
#include "DataAccess/RepositoryFactory.h"

int main() {
    DataAccess::MapDaoFactory daoFactory = DataAccess::MapDaoFactory();
    DataAccess::RepositoryFactory repositoryFactory = DataAccess::RepositoryFactory(daoFactory);
    Service::StorageService *storageService = Service::StorageService::getInstance();
    storageService->setRepositoryFactory(&repositoryFactory);

    UI::CLIUserInterface userInterface;

    userInterface.start();
    return 0;
}
