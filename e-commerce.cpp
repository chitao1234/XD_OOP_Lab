#include "UI/CLIUserInterface.h"
#include "DataAccess/MapUserRepository.h"
#include "DataAccess/MapProductRepository.h"
#include "Service/StorageService.h"
#include "DataAccess/CouponRepository.h"
#include "DataAccess/MapDaoFactory.h"

int main() {
    DataAccess::MapDaoFactory daoFactory = DataAccess::MapDaoFactory();
    DataAccess::MapUserRepository userRepository = DataAccess::MapUserRepository(daoFactory);
    DataAccess::MapProductRepository productRepository = DataAccess::MapProductRepository(daoFactory);
    DataAccess::CouponRepository couponRepository = DataAccess::CouponRepository(daoFactory);
    Service::StorageService *storageService = Service::StorageService::getInstance();
    storageService->setDaoFactory(daoFactory);
    storageService->setUserRepository(userRepository);
    storageService->setProductRepository(productRepository);
    storageService->setCouponRepository(couponRepository);

    UI::CLIUserInterface userInterface;

    userInterface.start();
    return 0;
}
