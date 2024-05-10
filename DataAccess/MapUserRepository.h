#ifndef MAPUSERREPOSITORY_H
#define MAPUSERREPOSITORY_H

#include <vector>
#include "../DataType/AdminUser.h"
#include "MapUserDao.h"
#include "IUserRepository.h"
#include "../DataType/NormalUser.h"

class MapUserRepository : public IUserRepository {
private:
    IUserDao<NormalUser> *userDao;
    IUserDao<AdminUser> *adminDao;

public:
    MapUserRepository();

    ~MapUserRepository();

    NormalUser findUserByUsername(std::string username) override;

    bool registerUser(const NormalUser &user) override;

    std::optional<NormalUser> login(std::string username, std::string password) override;

    bool loginAsAdmin(std::string username, std::string password) override;

    bool changePassword(const NormalUser &user, std::string oldPassword, std::string newPassword) override;

    bool updateUser(const NormalUser &user) override;

    bool deleteUser(std::string username) override;

    bool replaceUser(const NormalUser &user, const NormalUser &newUser) override;

    std::vector<NormalUser> listUsers() override;
};


#endif
