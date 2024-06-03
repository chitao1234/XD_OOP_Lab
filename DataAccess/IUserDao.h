#ifndef IUSERDAO_H
#define IUSERDAO_H

#include <string>
#include <vector>

namespace DataAccess {
    // 用户数据访问对象接口，用于底层数据存储访问，采用模板类，支持不同的用户数据类型
    template<typename T>
    class IUserDao {
    public:
        // 接口需要使用虚析构函数
        virtual ~IUserDao() = default;

        // 获取用户
        virtual T getUser(std::string username) = 0;

        // 添加用户
        virtual bool addUser(const T &user) = 0;

        // 更新用户信息
        virtual bool updateUser(const T &user) = 0;

        // 删除用户
        virtual void deleteUser(std::string username) = 0;

        // 判断用户是否存在
        virtual bool containUser(std::string username) = 0;

        // 获取所有用户
        virtual std::vector<T> listUsers() = 0;

        // 保存数据
        virtual void save() = 0;

        // 加载数据
        virtual bool load() = 0;
    };
}

#endif
