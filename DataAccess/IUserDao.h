#ifndef IUSERDAO_H
#define IUSERDAO_H

#include <string>
#include <vector>

namespace DataAccess {
    template<typename T>
    class IUserDao {
    public:
        virtual ~IUserDao() = default;

        virtual T getUser(std::string username) = 0;

        virtual bool addUser(const T &user) = 0;

        virtual bool updateUser(const T &user) = 0;

        virtual void deleteUser(std::string username) = 0;

        virtual bool containUser(std::string username) = 0;

        virtual std::vector<T> listUsers() = 0;

        virtual void save() = 0;

        virtual bool load() = 0;
    };
}

#endif
