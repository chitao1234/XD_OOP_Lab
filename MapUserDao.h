#ifndef MAPUSERDAO_H
#define MAPUSERDAO_H
#include <map>
#include <fstream>
#include <sstream>

#include "IUserDao.h"

template<typename T>
class MapUserDao : public IUserDao<T> {
   private:
    std::string filename;
    std::map<std::string, T> users;

   public:
    explicit MapUserDao(const std::string &filename);
    ~MapUserDao();

    T getUser(std::string username);
    bool addUser(const T &user);
    bool updateUser(const T &user);
    void deleteUser(std::string username);
    void save();

    bool containUser(std::string username);

    bool load();
};

template<typename T>
MapUserDao<T>::MapUserDao(const std::string &filename) : filename(filename) {
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
    std::ofstream file(filename.c_str());
    for (typename std::map<std::string, T>::const_iterator iter = users.begin(); iter != users.end(); ++iter) {
        file << iter->second.getUsername() << "," << iter->second.getPasswordHash() << "\n";
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
        std::istringstream iss(line);
        std::string username, password;
        getline(iss, username, ',');
        getline(iss, password, ',');
        addUser(T(username, password));
    }
    file.close();
    return true;
}

template<typename T>
MapUserDao<T>::~MapUserDao() {
    MapUserDao::save();
}

#endif
