#ifndef USER_H
#define USER_H
#include <string>

class User {
   public:
    User(std::string  username, std::string  password);
    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] std::string getPasswordHash() const;
    [[nodiscard]] bool verifyPassword(const std::string& password) const;

   private:
    std::string username;
    std::string passwordHash;
};
#endif
