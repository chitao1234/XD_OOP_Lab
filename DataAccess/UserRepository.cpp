#include "UserRepository.h"

namespace DataAccess {
    UserRepository::UserRepository(IDaoFactory &daoFactory) :
            userDao(daoFactory.getUserDao()),
            adminDao(daoFactory.getAdminDao()) {}

    UserRepository::~UserRepository() {
        delete userDao;
        delete adminDao;
    }

    DataType::NormalUser UserRepository::findUserByUsername(std::string username) {
        return userDao->getUser(username);
    }

    bool UserRepository::registerUser(const DataType::NormalUser &user) {
        if (!userDao->containUser(user.getUsername()) && userDao->addUser(user)) {
            userDao->save();
            return true;
        } else {
            return false;
        }
    }

    // 不存在用户和密码错误均返回空
    std::optional<DataType::NormalUser> UserRepository::login(std::string username, std::string password) {
        if (!userDao->containUser(username)) {
            return {};
        }
        DataType::NormalUser user = userDao->getUser(username);
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
        DataType::AdminUser user = adminDao->getUser(username);
        return user.verifyPassword(password);
    }

    bool
    UserRepository::changePassword(const DataType::NormalUser &user, std::string oldPassword, std::string newPassword) {
        if (user.verifyPassword(oldPassword)) {
            DataType::NormalUser newUser = DataType::NormalUser(user.getUsername(), newPassword, user.getEmail());
            userDao->updateUser(newUser);
            userDao->save();
            return true;
        } else {
            return false;
        }
    }

    bool UserRepository::updateUser(const DataType::NormalUser &user) {
        // 不支持用户名更改
        if (!userDao->containUser(user.getUsername())) {
            return false;
        }
        DataType::NormalUser originalUser = userDao->getUser(user.getUsername());
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
    bool UserRepository::replaceUser(const DataType::NormalUser &user, const DataType::NormalUser &newUser) {
        if (!userDao->containUser(user.getUsername())) {
            return false;
        }
        userDao->deleteUser(user.getUsername());
        userDao->addUser(newUser);
        userDao->save();
        return true;
    }

    std::vector<DataType::NormalUser> UserRepository::listUsers() {
        return userDao->listUsers();
    }

    DataType::NormalUser UserRepository::getRandomUser() {
        std::vector<DataType::NormalUser> users = userDao->listUsers();
        if (users.empty()) {
            throw std::runtime_error("No user in the repository");
        }
        return users[rand() % users.size()];
    }
}