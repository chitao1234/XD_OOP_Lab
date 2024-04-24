#ifndef IUSERDAO_H
#define IUSERDAO_H
#include "User.h"

class IUserDao {
   public:
    virtual ~IUserDao() {};

    virtual User getUser(std::string username) = 0;
    virtual bool addUser(const User &user) = 0;
    virtual bool updateUser(const User &user) = 0;
    virtual void deleteUser(std::string username) = 0;
    virtual bool containUser(std::string username) = 0;
    virtual void save() = 0;
    virtual bool load() = 0;
};
#endif
