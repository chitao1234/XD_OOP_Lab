#ifndef MAPUSERDAO_H
#define MAPUSERDAO_H

#include <map>
#include <fstream>
#include <sstream>
#include <utility>

#include "IUserDao.h"

template<typename T>
class MapUserDao : public IUserDao<T> {
private:
    std::string filename;
    std::map<std::string, T> users;

public:
    explicit MapUserDao(std::string filename);

    ~MapUserDao();

    T getUser(std::string username) override;

    bool addUser(const T &user) override;

    bool updateUser(const T &user) override;

    void deleteUser(std::string username) override;

    bool containUser(std::string username) override;

    std::vector<T> listUsers() override;

    void save() override;

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
    std::ofstream file(filename.c_str());
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
        addUser(T::deserializeUser(line));
    }
    file.close();
    return true;
}

template<typename T>
MapUserDao<T>::~MapUserDao() {
    MapUserDao::save();
}

#endif
