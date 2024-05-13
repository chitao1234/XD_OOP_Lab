#include "UI/CLIUserInterface.h"
#include "DataAccess/MapUserRepository.h"
#include "DataAccess/MapProductRepository.h"
#include "Service/StorageService.h"
#include "DataAccess/CouponRepository.h"

int main() {
    DataAccess::MapUserRepository userRepository = DataAccess::MapUserRepository();
    DataAccess::MapProductRepository productRepository = DataAccess::MapProductRepository();
    DataAccess::CouponRepository couponRepository = DataAccess::CouponRepository();
    Service::StorageService::getInstance()->setUserRepository(userRepository);
    Service::StorageService::getInstance()->setProductRepository(productRepository);
    Service::StorageService::getInstance()->setCouponRepository(couponRepository);

    UI::CLIUserInterface userInterface;

    userInterface.start();
    return 0;
}
