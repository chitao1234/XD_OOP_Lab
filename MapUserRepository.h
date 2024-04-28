#ifndef MAPUSERREPOSITORY_H
#define MAPUSERREPOSITORY_H

#include "AdminUser.h"
#include "MapUserDao.h"
#include "IUserRepository.h"
#include "NormalUser.h"

class MapUserRepository : public IUserRepository {
private:
    MapUserDao<NormalUser> userDao;
    MapUserDao<AdminUser> adminDao;

public:
    MapUserRepository();

    NormalUser findUserByUsername(std::string username);

    bool registerUser(const NormalUser &user);

    std::optional<NormalUser> login(std::string username, std::string password);

    bool loginAsAdmin(std::string username, std::string password);

    bool changePassword(const NormalUser &user, std::string oldPassword, std::string newPassword);

    bool updateUser(const NormalUser &user);
};


#endif
