#include "MapUserRepository.h"

namespace DataAccess {
    using DataType::NormalUser;
    using DataType::AdminUser;

    MapUserRepository::MapUserRepository(IDaoFactory &daoFactory) :
            userDao(daoFactory.getUserDao()),
            adminDao(daoFactory.getAdminDao()) {}

    MapUserRepository::~MapUserRepository() {
        delete userDao;
        delete adminDao;
    }

    NormalUser MapUserRepository::findUserByUsername(std::string username) {
        return userDao->getUser(username);
    }

    bool MapUserRepository::registerUser(const NormalUser &user) {
        if (!userDao->containUser(user.getUsername()) && userDao->addUser(user)) {
            userDao->save();
            return true;
        } else {
            return false;
        }
    }

    std::optional<NormalUser> MapUserRepository::login(std::string username, std::string password) {
        if (!userDao->containUser(username)) {
            return {};
        }
        NormalUser user = userDao->getUser(username);
        if (user.verifyPassword(password)) {
            return user;
        } else {
            return {};
        }
    }

    bool MapUserRepository::loginAsAdmin(std::string username, std::string password) {
        if (!adminDao->containUser(username)) {
            return false;
        }
        AdminUser user = adminDao->getUser(username);
        return user.verifyPassword(password);
    }

    bool MapUserRepository::changePassword(const NormalUser &user, std::string oldPassword, std::string newPassword) {
        if (user.verifyPassword(oldPassword)) {
            NormalUser newUser = NormalUser(user.getUsername(), newPassword, user.getEmail());
            userDao->updateUser(newUser);
            userDao->save();
            return true;
        } else {
            return false;
        }
    }

    bool MapUserRepository::updateUser(const NormalUser &user) {
        // 不支持用户名更改
        NormalUser originalUser = userDao->getUser(user.getUsername());
        if (originalUser.getUsername() != user.getUsername() || !originalUser.verifyPassword(user.getPasswordHash())) {
            return false;
        }
        userDao->updateUser(user);
        userDao->save();
        return true;
    }

    bool MapUserRepository::deleteUser(std::string username) {
        if (!userDao->containUser(username)) {
            return false;
        }
        userDao->deleteUser(username);
        userDao->save();
        return true;
    }

    bool MapUserRepository::replaceUser(const NormalUser &user, const NormalUser &newUser) {
        if (!userDao->containUser(user.getUsername())) {
            return false;
        }
        userDao->deleteUser(user.getUsername());
        userDao->addUser(newUser);
        userDao->save();
        return true;
    }

    std::vector<NormalUser> MapUserRepository::listUsers() {
        return userDao->listUsers();
    }

    DataType::NormalUser MapUserRepository::getRandomUser() {
        std::vector<NormalUser> users = userDao->listUsers();
        if (users.empty()) {
            throw std::runtime_error("No user in the repository");
        }
        return users[rand() % users.size()];
    }
}