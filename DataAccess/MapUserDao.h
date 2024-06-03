#ifndef MAPUSERDAO_H
#define MAPUSERDAO_H

#include <map>
#include <fstream>
#include <sstream>

#include "IUserDao.h"

namespace DataAccess {
    // 用户数据访问对象，采用模板支持多种用户类型，使用map存储，文件持久化
    template<typename T>
    class MapUserDao : public IUserDao<T> {
    private:
        std::string filename;
        std::map<std::string, T> users;

    public:
        explicit MapUserDao(std::string filename);

        ~MapUserDao();

        // 获取用户信息
        T getUser(std::string username) override;

        // 添加用户
        bool addUser(const T &user) override;

        // 更新用户信息
        bool updateUser(const T &user) override;

        // 删除用户
        void deleteUser(std::string username) override;

        // 判断用户是否存在
        bool containUser(std::string username) override;

        // 获取所有用户
        std::vector<T> listUsers() override;

        // 保存数据
        void save() override;

        // 加载数据
        bool load() override;
    };

    template<typename T>
    std::vector<T> MapUserDao<T>::listUsers() {
        std::vector<T> result;
        for (typename std::map<std::string, T>::const_iterator iter = users.begin(); iter != users.end(); ++iter) {
            result.push_back(iter->second);
        }
        return result;
    }

    // 创建时进行数据加载
    template<typename T>
    MapUserDao<T>::MapUserDao(std::string filename) : filename(std::move(filename)) {
        MapUserDao::load();
    }

    template<typename T>
    bool MapUserDao<T>::containUser(std::string username) {
        return users.find(username) != users.end();
    }

    template<typename T>
    T MapUserDao<T>::getUser(std::string username) {
        return users.at(username);
    }

    template<typename T>
    bool MapUserDao<T>::addUser(const T &user) {
        if (containUser(user.getUsername())) return false;
        users.insert(make_pair(user.getUsername(), user));
        return true;
    }

    template<typename T>
    bool MapUserDao<T>::updateUser(const T &user) {
        if (!containUser(user.getUsername())) return false;
        users.at(user.getUsername()) = user;
        return true;
    }

    template<typename T>
    void MapUserDao<T>::deleteUser(std::string username) {
        users.erase(username);
    }

    template<typename T>
    void MapUserDao<T>::save() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file " + filename);
        }

        // 使用对应类型的序列化函数保存数据
        for (typename std::map<std::string, T>::const_iterator iter = users.begin(); iter != users.end(); ++iter) {
            file << T::serializeUser(iter->second) << '\n';
        }
        file.close();
    }

    template<typename T>
    bool MapUserDao<T>::load() {
        std::ifstream file(filename.c_str());
        if (file.bad()) {
            return false;
        }

        std::string line;
        while (getline(file, line)) {
            // 使用对应类型的反序列化函数加载数据
            addUser(T::deserializeUser(line));
        }
        file.close();
        return true;
    }

    // 析构时保存数据
    template<typename T>
    MapUserDao<T>::~MapUserDao() {
        MapUserDao::save();
    }
}

#endif
