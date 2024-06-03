//
// Created by chi on 24/05/27.
//

#ifndef E_COMMERCE_ICATEGORYDAO_H
#define E_COMMERCE_ICATEGORYDAO_H

#include <string>
#include <map>
#include <cstdint>

namespace DataAccess {
    // 商品分类数据访问对象接口，用于底层数据存储访问
    class ICategoryDao {
    public:
        // 接口需要使用虚析构函数
        virtual ~ICategoryDao() = default;

        // 添加商品分类
        virtual void addCategory(uint64_t id, std::string category) = 0;

        // 移除商品分类
        virtual void removeCategory(uint64_t id) = 0;

        // 判断是否包含某个分类名
        virtual bool containCategory(std::string category) = 0;

        // 获取所有分类
        virtual std::map<uint64_t, std::string> getCategories() = 0;

        // 根据分类名获取分类ID
        virtual uint64_t getId(std::string category) = 0;

        // 根据分类ID获取分类名
        virtual std::string getCategory(uint64_t id) = 0;

        // 获取下一个分类ID
        virtual uint64_t nextId() = 0;

        // 保存数据
        virtual void save() = 0;

        // 加载数据
        virtual bool load() = 0;
    };
}

#endif //E_COMMERCE_ICATEGORYDAO_H
