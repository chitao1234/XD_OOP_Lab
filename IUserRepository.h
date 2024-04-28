#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H
#include "NormalUser.h"

class IUserRepository {
public:
    virtual ~IUserRepository() {};

    virtual NormalUser findUserByUsername(std::string username) = 0;
    virtual bool registerUser(const NormalUser& user) = 0;
    virtual bool login(std::string username, std::string password) = 0;
    virtual bool loginAsAdmin(std::string username, std::string password) = 0;
};
#endif
