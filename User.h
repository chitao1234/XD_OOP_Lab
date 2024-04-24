#ifndef USER_H
#define USER_H
#include <string>

class User {
   public:
    User(const std::string& username, const std::string& password);
    std::string getUsername() const;
    std::string getPasswordHash() const;
    bool verifyPassword(const std::string& password) const;

   private:
    std::string username;
    std::string passwordHash;
    std::string email;
};
#endif
