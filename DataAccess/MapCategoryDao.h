//
// Created by chi on 24/05/27.
//

#ifndef E_COMMERCE_MAPCATEGORYDAO_H
#define E_COMMERCE_MAPCATEGORYDAO_H

#include "ICategoryDao.h"

namespace DataAccess {

    class MapCategoryDao : public ICategoryDao {
    public:
        explicit MapCategoryDao(std::string filename);

        ~MapCategoryDao() override;

        void addCategory(uint64_t id, std::string category) override;

        void removeCategory(uint64_t id) override;

        bool containCategory(std::string category) override;

        std::map<uint64_t, std::string> getCategories() override;

        uint64_t getId(std::string category) override;

        std::string getCategory(uint64_t id) override;

        uint64_t nextId() override;

        void save() override;

        bool load() override;

    private:
        std::string filename;
        std::map<uint64_t, std::string> categories;
    };

} // DataAccess

#endif //E_COMMERCE_MAPCATEGORYDAO_H
