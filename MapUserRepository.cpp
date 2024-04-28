#include "MapUserRepository.h"

MapUserRepository::MapUserRepository() : userDao("users.csv"), adminDao("admin.csv") {}

User MapUserRepository::findUserByUsername(std::string username) {
    return userDao.getUser(username);
}

bool MapUserRepository::registerUser(const NormalUser &user) {
    if (userDao.addUser(user)) {
        userDao.save();
        return true;
    } else {
        return false;
    }
}

bool MapUserRepository::login(std::string username, std::string password) {
    if (!userDao.containUser(username)) {
        return false;
    }
    NormalUser user = userDao.getUser(username);
    return user.verifyPassword(password);
}

bool MapUserRepository::loginAsAdmin(std::string username, std::string password) {
    if (!adminDao.containUser(username)) {
        return false;
    }
    AdminUser user = adminDao.getUser(username);
    return user.verifyPassword(password);
}
