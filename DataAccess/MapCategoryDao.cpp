//
// Created by chi on 24/05/27.
//

#include <fstream>
#include "MapCategoryDao.h"

namespace DataAccess {

    MapCategoryDao::MapCategoryDao(std::string filename) : filename(std::move(filename)) {
        MapCategoryDao::load();
    }

    MapCategoryDao::~MapCategoryDao() {
        MapCategoryDao::save();
    }

    void MapCategoryDao::addCategory(uint64_t id, std::string category) {
        categories.insert({id, category});
    }

    void MapCategoryDao::removeCategory(uint64_t id) {
        categories.erase(id);
    }

    std::map<uint64_t, std::string> MapCategoryDao::getCategories() {
        return categories;
    }

    uint64_t MapCategoryDao::nextId() {
        if (categories.empty()) {
            return 1;
        }
        return categories.rbegin()->first + 1;
    }

    void MapCategoryDao::save() {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file " + filename);
        }
        for (const auto &category: categories) {
            file << category.first << "," << category.second << std::endl;
        }
    }

    bool MapCategoryDao::load() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        categories.clear();
        std::string category, id;
        while (std::getline(file, id, ',')) {
            std::getline(file, category);
            categories.insert({std::stoull(id), category});
        }
        return true;
    }

    uint64_t MapCategoryDao::getId(std::string category) {
        for (const auto &pair: categories) {
            if (pair.second == category) {
                return pair.first;
            }
        }
        throw std::runtime_error("Category not found");
    }

    std::string MapCategoryDao::getCategory(uint64_t id) {
        return categories.at(id);
    }

    bool MapCategoryDao::containCategory(std::string category) {
        for (const auto &pair: categories) {
            if (pair.second == category) {
                return true;
            }
        }
        return false;
    }
} // DataAccess