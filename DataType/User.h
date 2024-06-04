#ifndef USER_H
#define USER_H

#include <string>

namespace DataType {
    // 用户基类，包含用户名和密码，处理用户登录验证
    class User {
    public:
        User(std::string username, std::string password);

        [[nodiscard]] std::string getUsername() const;

        [[nodiscard]] std::string getPasswordHash() const;

        // 验证密码是否正确
        [[nodiscard]] bool verifyPassword(const std::string &password) const;

    private:
        std::string username;
        std::string passwordHash;
    };
}

#endif
