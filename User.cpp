#include "User.h"

User::User(const std::string& username, const std::string& password)
    : username(username), passwordHash(password) {
}

std::string User::getUsername() const {
    return username;
}

bool User::verifyPassword(const std::string& password) const {
    return this->passwordHash == password;
}

std::string User::getPasswordHash() const {
    return passwordHash;
}
