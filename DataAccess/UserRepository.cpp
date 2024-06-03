#include "UserRepository.h"

namespace DataAccess {
    using DataType::NormalUser;
    using DataType::AdminUser;

    UserRepository::UserRepository(IDaoFactory &daoFactory) :
            userDao(daoFactory.getUserDao()),
            adminDao(daoFactory.getAdminDao()) {}

    UserRepository::~UserRepository() {
        delete userDao;
        delete adminDao;
    }

    NormalUser UserRepository::findUserByUsername(std::string username) {
        return userDao->getUser(username);
    }

    bool UserRepository::registerUser(const NormalUser &user) {
        if (!userDao->containUser(user.getUsername()) && userDao->addUser(user)) {
            userDao->save();
            return true;
        } else {
            return false;
        }
    }

    // 不存在用户和密码错误均返回空
    std::optional<NormalUser> UserRepository::login(std::string username, std::string password) {
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

    bool UserRepository::loginAsAdmin(std::string username, std::string password) {
        if (!adminDao->containUser(username)) {
            return false;
        }
        AdminUser user = adminDao->getUser(username);
        return user.verifyPassword(password);
    }

    bool UserRepository::changePassword(const NormalUser &user, std::string oldPassword, std::string newPassword) {
        if (user.verifyPassword(oldPassword)) {
            NormalUser newUser = NormalUser(user.getUsername(), newPassword, user.getEmail());
            userDao->updateUser(newUser);
            userDao->save();
            return true;
        } else {
            return false;
        }
    }

    bool UserRepository::updateUser(const NormalUser &user) {
        // 不支持用户名更改
        if (!userDao->containUser(user.getUsername())) {
            return false;
        }
        NormalUser originalUser = userDao->getUser(user.getUsername());
        // 该方法不支持修改密码
        if (!originalUser.verifyPassword(user.getPasswordHash())) {
            return false;
        }
        userDao->updateUser(user);
        userDao->save();
        return true;
    }

    bool UserRepository::deleteUser(std::string username) {
        if (!userDao->containUser(username)) {
            return false;
        }
        userDao->deleteUser(username);
        userDao->save();
        return true;
    }

    // 使用该方法更换密码
    bool UserRepository::replaceUser(const NormalUser &user, const NormalUser &newUser) {
        if (!userDao->containUser(user.getUsername())) {
            return false;
        }
        userDao->deleteUser(user.getUsername());
        userDao->addUser(newUser);
        userDao->save();
        return true;
    }

    std::vector<NormalUser> UserRepository::listUsers() {
        return userDao->listUsers();
    }

    DataType::NormalUser UserRepository::getRandomUser() {
        std::vector<NormalUser> users = userDao->listUsers();
        if (users.empty()) {
            throw std::runtime_error("No user in the repository");
        }
        return users[rand() % users.size()];
    }
}