#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"

class AdminUser: public User {
public:
    AdminUser(const std::string& username, const std::string& password);

    // TODO: admin
};

#endif
