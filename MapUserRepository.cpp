#include "MapUserRepository.h"

MapUserRepository::MapUserRepository() : userDao("users.csv"), adminDao("admin.csv") {}

NormalUser MapUserRepository::findUserByUsername(std::string username) {
    return userDao.getUser(username);
}

bool MapUserRepository::registerUser(const NormalUser &user) {
    if (!userDao.containUser(user.getUsername()) && userDao.addUser(user)) {
        userDao.save();
        return true;
    } else {
        return false;
    }
}

std::optional<NormalUser> MapUserRepository::login(std::string username, std::string password) {
    if (!userDao.containUser(username)) {
        return {};
    }
    NormalUser user = userDao.getUser(username);
    if (user.verifyPassword(password)) {
        return user;
    } else {
        return {};
    }
}

bool MapUserRepository::loginAsAdmin(std::string username, std::string password) {
    if (!adminDao.containUser(username)) {
        return false;
    }
    AdminUser user = adminDao.getUser(username);
    return user.verifyPassword(password);
}
