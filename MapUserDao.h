#ifndef MAPUSERDAO_H
#define MAPUSERDAO_H
#include <map>

#include "IUserDao.h"

class MapUserDao : public IUserDao {
   private:
    std::string filename;
    std::map<std::string, User> users;

   public:
    explicit MapUserDao(const std::string &filename);
    ~MapUserDao();

    User getUser(std::string username);
    bool addUser(const User &user);
    bool updateUser(const User &user);
    void deleteUser(std::string username);
    void save();

    bool containUser(std::string username);

    bool load();
};
#endif
