//
// Created by chi on 24/05/27.
//

#ifndef E_COMMERCE_MAPCATEGORYDAO_H
#define E_COMMERCE_MAPCATEGORYDAO_H

#include "ICategoryDao.h"

namespace DataAccess {
    // 商品分类数据访问对象，使用map缓存，文件持久化
    class MapCategoryDao : public ICategoryDao {
    public:
        explicit MapCategoryDao(std::string filename);

        ~MapCategoryDao() override;

        // 添加商品分类
        void addCategory(uint64_t id, std::string category) override;

        // 移除商品分类
        void removeCategory(uint64_t id) override;

        // 判断是否包含某个分类名
        bool containCategory(std::string category) override;

        // 获取所有分类
        std::map<uint64_t, std::string> getCategories() override;

        // 根据分类名获取分类ID
        uint64_t getId(std::string category) override;

        // 根据分类ID获取分类名
        std::string getCategory(uint64_t id) override;

        // 获取下一个分类ID
        uint64_t nextId() override;

        // 保存数据
        void save() override;

        // 加载数据
        bool load() override;

    private:
        std::string filename;
        std::map<uint64_t, std::string> categories;
    };

} // DataAccess

#endif //E_COMMERCE_MAPCATEGORYDAO_H
