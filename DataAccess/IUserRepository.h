#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include <optional>
#include "DataType/NormalUser.h"

namespace DataAccess {
    // 用户数据仓储接口，用于与外界交互
    class IUserRepository {
    public:
        // 接口需要使用虚析构函数
        virtual ~IUserRepository() = default;

        // 根据用户名查找用户
        virtual DataType::NormalUser findUserByUsername(std::string username) = 0;

        // 注册用户
        virtual bool registerUser(const DataType::NormalUser &user) = 0;

        // 登录
        virtual std::optional<DataType::NormalUser> login(std::string username, std::string password) = 0;

        // 以管理员身份登录
        virtual bool loginAsAdmin(std::string username, std::string password) = 0;

        // 修改密码
        virtual bool changePassword(const DataType::NormalUser &user, std::string oldPassword, std::string newPassword) = 0;

        // 更新用户信息
        virtual bool updateUser(const DataType::NormalUser &User) = 0;

        // 删除用户
        virtual bool deleteUser(std::string username) = 0;

        // 替换用户，用于用户更新密码等
        virtual bool replaceUser(const DataType::NormalUser &user, const DataType::NormalUser &newUser) = 0;

        // 获取所有用户
        virtual std::vector<DataType::NormalUser> listUsers() = 0;

        // 随机获取一个用户，用于活动
        virtual DataType::NormalUser getRandomUser() = 0;
    };
}

#endif
