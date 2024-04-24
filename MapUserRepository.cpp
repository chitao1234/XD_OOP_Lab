#include "MapUserRepository.h"

MapUserRepository::MapUserRepository() : userDao("users.csv") {}

User MapUserRepository::findUserByUsername(std::string username) {
    return userDao.getUser(username);
}

bool MapUserRepository::registerUser(const User &user) {
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
    User user = userDao.getUser(username);
    return user.verifyPassword(password);
}
