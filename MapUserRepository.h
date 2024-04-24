#ifndef MAPUSERREPOSITORY_H
#define MAPUSERREPOSITORY_H
#include "MapUserDao.h"
#include "IUserRepository.h"

class MapUserRepository : public IUserRepository {
   private:
    MapUserDao userDao;

   public:
    MapUserRepository();
    User findUserByUsername(std::string username);
    bool registerUser(const User &user);
    bool login(std::string username, std::string password);
};
#endif
