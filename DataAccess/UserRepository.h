#ifndef MAPUSERREPOSITORY_H
#define MAPUSERREPOSITORY_H

#include <vector>
#include "DataType/AdminUser.h"
#include "MapUserDao.h"
#include "IUserRepository.h"
#include "DataType/NormalUser.h"
#include "IDaoFactory.h"

namespace DataAccess {
    // 用户数据仓储，使用数据访问对象工厂实现，与底层解耦
    class UserRepository : public IUserRepository {
    private:
        IUserDao<DataType::NormalUser> *userDao;
        IUserDao<DataType::AdminUser> *adminDao;

    public:
        explicit UserRepository(IDaoFactory &daoFactory);

        ~UserRepository() override;

        // 获取用户信息
        DataType::NormalUser findUserByUsername(std::string username) override;

        // 添加用户
        bool registerUser(const DataType::NormalUser &user) override;

        // 登录
        std::optional<DataType::NormalUser> login(std::string username, std::string password) override;

        // 管理员登录
        bool loginAsAdmin(std::string username, std::string password) override;

        // 修改密码
        bool changePassword(const DataType::NormalUser &user, std::string oldPassword, std::string newPassword) override;

        // 更新用户信息
        bool updateUser(const DataType::NormalUser &user) override;

        // 删除用户
        bool deleteUser(std::string username) override;

        // 替换用户，更换密码时使用
        bool replaceUser(const DataType::NormalUser &user, const DataType::NormalUser &newUser) override;

        // 管理员列出所有用户
        std::vector<DataType::NormalUser> listUsers() override;

        // 活动时随机获取用户
        DataType::NormalUser getRandomUser() override;
    };
}


#endif
