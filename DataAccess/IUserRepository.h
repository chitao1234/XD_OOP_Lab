#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include <optional>
#include "../DataType/NormalUser.h"

class IUserRepository {
public:
    virtual ~IUserRepository() = default;

    virtual NormalUser findUserByUsername(std::string username) = 0;

    virtual bool registerUser(const NormalUser &user) = 0;

    virtual std::optional<NormalUser> login(std::string username, std::string password) = 0;

    virtual bool loginAsAdmin(std::string username, std::string password) = 0;

    virtual bool changePassword(const NormalUser& user, std::string oldPassword, std::string newPassword) = 0;

    virtual bool updateUser(const NormalUser &User) = 0;

    virtual bool deleteUser(std::string username) = 0;

    virtual bool replaceUser(const NormalUser &user, const NormalUser &newUser) = 0;

    virtual std::vector<NormalUser> listUsers() = 0;
};

#endif
