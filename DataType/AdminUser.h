#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"

namespace DataType {
    // 管理员用户类，继承自用户类
    class AdminUser : public User {
    public:
        AdminUser(const std::string &username, const std::string &password);

        // 反序列化用户，用于从文件中读取用户信息
        static AdminUser deserializeUser(const std::string &line);

        // 序列化用户，用于将用户信息写入文件
        static std::string serializeUser(const AdminUser &user);
    };
}

#endif
