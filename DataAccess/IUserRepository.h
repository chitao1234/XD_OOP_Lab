#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include <optional>
#include "DataType/NormalUser.h"

namespace DataAccess {
    class IUserRepository {
    public:
        virtual ~IUserRepository() = default;

        virtual DataType::NormalUser findUserByUsername(std::string username) = 0;

        virtual bool registerUser(const DataType::NormalUser &user) = 0;

        virtual std::optional<DataType::NormalUser> login(std::string username, std::string password) = 0;

        virtual bool loginAsAdmin(std::string username, std::string password) = 0;

        virtual bool changePassword(const DataType::NormalUser &user, std::string oldPassword, std::string newPassword) = 0;

        virtual bool updateUser(const DataType::NormalUser &User) = 0;

        virtual bool deleteUser(std::string username) = 0;

        virtual bool replaceUser(const DataType::NormalUser &user, const DataType::NormalUser &newUser) = 0;

        virtual std::vector<DataType::NormalUser> listUsers() = 0;

        virtual DataType::NormalUser getRandomUser() = 0;
    };
}

#endif
