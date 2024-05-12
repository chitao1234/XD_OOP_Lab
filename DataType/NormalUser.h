#ifndef NORMALUSER_H
#define NORMALUSER_H

#include <string>

#include "User.h"

namespace DataType {
    class NormalUser : public User {
    public:
        NormalUser(const std::string &username, const std::string &password, std::string email);

        [[nodiscard]] std::string getEmail() const;

        void setEmail(const std::string &email);

        static NormalUser deserializeUser(const std::string &line);

        static std::string serializeUser(const NormalUser &user);
    private:
        std::string email;
    };
}

#endif
