//
// Created by chi on 24/05/27.
//

#ifndef E_COMMERCE_ICATEGORYDAO_H
#define E_COMMERCE_ICATEGORYDAO_H

#include <string>
#include <map>
#include <cstdint>

namespace DataAccess {
    class ICategoryDao {
    public:
        virtual ~ICategoryDao() = default;

        virtual void addCategory(uint64_t id, std::string category) = 0;

        virtual void removeCategory(uint64_t id) = 0;

        virtual bool containCategory(std::string category) = 0;

        virtual std::map<uint64_t, std::string> getCategories() = 0;

        virtual uint64_t getId(std::string category) = 0;

        virtual std::string getCategory(uint64_t id) = 0;

        virtual uint64_t nextId() = 0;

        virtual void save() = 0;

        virtual bool load() = 0;
    };
}

#endif //E_COMMERCE_ICATEGORYDAO_H
