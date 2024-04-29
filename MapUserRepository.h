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

    NormalUser findUserByUsername(std::string username) override;

    bool registerUser(const NormalUser &user) override;

    std::optional<NormalUser> login(std::string username, std::string password) override;

    bool loginAsAdmin(std::string username, std::string password) override;

    bool changePassword(const NormalUser &user, std::string oldPassword, std::string newPassword) override;

    bool updateUser(const NormalUser &user) override;
};


#endif
