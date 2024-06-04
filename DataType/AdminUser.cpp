#include <sstream>
#include "AdminUser.h"

namespace DataType {
    AdminUser::AdminUser(const std::string &username, const std::string &password)
            : User(username, password) {
    }

    AdminUser AdminUser::deserializeUser(const std::string &line) {
        // 采用CSV格式，以逗号分隔
        std::istringstream iss(line);
        std::string username, password, email;
        getline(iss, username, ',');
        getline(iss, password, ',');
        return AdminUser(username, password);
    }

    std::string AdminUser::serializeUser(const AdminUser &user) {
        std::ostringstream oss;
        oss << user.getUsername() << ',' << user.getPasswordHash();
        return oss.str();
    }
}
