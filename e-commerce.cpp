#include "UI/CLIUserInterface.h"
#include "Service/StorageService.h"
#include "DataAccess/MapDaoFactory.h"
#include "DataAccess/RepositoryFactory.h"

int main() {
    // 初始化数据访问层，初始化工厂并将工厂传递给服务层
    DataAccess::MapDaoFactory daoFactory = DataAccess::MapDaoFactory();
    DataAccess::RepositoryFactory repositoryFactory = DataAccess::RepositoryFactory(daoFactory);
    Service::StorageService *storageService = Service::StorageService::getInstance();
    storageService->setRepositoryFactory(&repositoryFactory);

    // 初始化用户界面
    UI::CLIUserInterface userInterface;

    userInterface.start();
    return 0;
}
