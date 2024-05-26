#ifndef MAPUSERREPOSITORY_H
#define MAPUSERREPOSITORY_H

#include <vector>
#include "../DataType/AdminUser.h"
#include "MapUserDao.h"
#include "IUserRepository.h"
#include "../DataType/NormalUser.h"
#include "IDaoFactory.h"

namespace DataAccess {
    class MapUserRepository : public IUserRepository {
    private:
        IUserDao<DataType::NormalUser> *userDao;
        IUserDao<DataType::AdminUser> *adminDao;

    public:
        MapUserRepository(IDaoFactory &daoFactory);

        ~MapUserRepository() override;

        DataType::NormalUser findUserByUsername(std::string username) override;

        bool registerUser(const DataType::NormalUser &user) override;

        std::optional<DataType::NormalUser> login(std::string username, std::string password) override;

        bool loginAsAdmin(std::string username, std::string password) override;

        bool changePassword(const DataType::NormalUser &user, std::string oldPassword, std::string newPassword) override;

        bool updateUser(const DataType::NormalUser &user) override;

        bool deleteUser(std::string username) override;

        bool replaceUser(const DataType::NormalUser &user, const DataType::NormalUser &newUser) override;

        std::vector<DataType::NormalUser> listUsers() override;

        DataType::NormalUser getRandomUser() override;
    };
}


#endif
