#include <utility>
#include <vector>
#include "User.h"

User::User(std::string username, std::string password)
        : username(std::move(username)), passwordHash(std::move(password)) {
}

std::string User::getUsername() const {
    return username;
}

bool User::verifyPassword(const std::string &password) const {
    return this->passwordHash == password;
}

std::string User::getPasswordHash() const {
    return passwordHash;
}

