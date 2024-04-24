#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H
#include "User.h"

class IUserRepository {
public:
    virtual ~IUserRepository() {};

    virtual User findUserByUsername(std::string username) = 0;
    virtual bool registerUser(const User& user) = 0;
    virtual bool login(std::string username, std::string password) = 0;
};
#endif
