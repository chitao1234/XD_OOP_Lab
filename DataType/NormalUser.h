#ifndef NORMALUSER_H
#define NORMALUSER_H

#include <string>

#include "User.h"

namespace DataType {
    // 普通用户类，包含用户名、密码和邮箱
    class NormalUser : public User {
    public:
        NormalUser(const std::string &username, const std::string &password, std::string email);

        [[nodiscard]] std::string getEmail() const;

        void setEmail(const std::string &email);

        // 反序列化用户信息
        static NormalUser deserializeUser(const std::string &line);

        // 序列化用户信息
        static std::string serializeUser(const NormalUser &user);
    private:
        std::string email;
    };
}

#endif
