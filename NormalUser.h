#ifndef NORMALUSER_H
#define NORMALUSER_H

#include "User.h"

class NormalUser : public User {
public:
    NormalUser(const std::string& username, const std::string& password);
    // TODO: order product
};

#endif
