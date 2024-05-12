#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"

namespace DataType {
    class AdminUser : public User {
    public:
        AdminUser(const std::string &username, const std::string &password);

        static AdminUser deserializeUser(const std::string &line);

        static std::string serializeUser(const AdminUser &user);
    };
}

#endif
