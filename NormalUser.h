#ifndef NORMALUSER_H
#define NORMALUSER_H

#include <string>

#include "User.h"

class NormalUser : public User {
public:
    NormalUser(const std::string &username, const std::string &password, const std::string &email);

    std::string getEmail() const;

    void setEmail(const std::string &email);

    static NormalUser deserializeUser(const std::string &line);

    static std::string serializeUser(const NormalUser &user);
    // TODO: order product
private:
    std::string email;
};

#endif
