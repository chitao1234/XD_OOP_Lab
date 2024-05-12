#include <sstream>
#include <utility>
#include "NormalUser.h"

namespace DataType {
    NormalUser::NormalUser(const std::string &username, const std::string &password, std::string email)
            : User(username, password), email(std::move(email)) {
    }

    NormalUser NormalUser::deserializeUser(const std::string &line) {
        std::istringstream iss(line);
        std::string username, password, email;
        getline(iss, username, ',');
        getline(iss, password, ',');
        getline(iss, email, ',');
        return NormalUser(username, password, email);
    }

    std::string NormalUser::serializeUser(const NormalUser &user) {
        std::ostringstream oss;
        oss << user.getUsername() << ','
            << user.getPasswordHash() << ','
            << user.getEmail();
        return oss.str();
    }

    std::string NormalUser::getEmail() const {
        return email;
    }

    void NormalUser::setEmail(const std::string &email) {
        this->email = email;
    }
}