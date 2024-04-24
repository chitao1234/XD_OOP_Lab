#include "MapUserDao.h"
#include <fstream>
#include <sstream>

MapUserDao::MapUserDao(const std::string &filename) : filename(filename) {
    MapUserDao::load();
}

bool MapUserDao::containUser(std::string username) {
    return users.find(username) != users.end();
}

User MapUserDao::getUser(std::string username) {
    return users.at(username);
}

bool MapUserDao::addUser(const User &user) {
    if (containUser(user.getUsername())) return false;
    users.insert(make_pair(user.getUsername(), user));
    return true;
}

bool MapUserDao::updateUser(const User &user) {
    if (!containUser(user.getUsername())) return false;
    users.at(user.getUsername()) = user;
    return true;
}

void MapUserDao::deleteUser(std::string username) {
    users.erase(username);
}

void MapUserDao::save() {
    std::ofstream file(filename.c_str());
    for (std::map<std::string, User>::const_iterator iter = users.begin(); iter != users.end(); ++iter) {
        file << iter->second.getUsername() << "," << iter->second.getPasswordHash() << "\n";
    }
    file.close();
}

bool MapUserDao::load() {
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
        addUser(User(username, password));
    }
    file.close();
    return true;
}

MapUserDao::~MapUserDao() {
    MapUserDao::save();
}
