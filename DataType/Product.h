//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_PRODUCT_H
#define E_COMMERCE_PRODUCT_H

#include <string>
#include <cstdint>

namespace DataType {
    // 非完整商品类，不包含商品分类名称，用于保存到文件
    class Product {
    public:
        Product(uint64_t id,
                std::string name,
                std::string description,
                double price,
                long remainingStock,
                uint64_t categoryId);

        [[nodiscard]] uint64_t getId() const;

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] std::string getDescription() const;

        [[nodiscard]] double getPrice() const;

        [[nodiscard]] long getRemainingStock() const;

        [[nodiscard]] double getDiscount() const;

        [[nodiscard]] double getActualPrice() const;

        [[nodiscard]] uint64_t getCategoryId() const;

        void setName(std::string name);

        void setDescription(std::string description);

        void setPrice(double price);

        void setRemainingStock(long remainingStock);

        void setDiscount(double discount);

        void setCategoryId(uint64_t categoryId);

        // 序列化商品，用于保存到文件
        static std::string serialize(const Product &product);

        // 反序列化商品，用于从文件中读取
        static Product deserialize(const std::string &line);

        bool operator==(const Product &product) const;

    private:
        uint64_t id;
        std::string name;
        std::string description;
        double price;
        long remainingStock;
        double discount;
        uint64_t categoryId;
    };
}

#endif //E_COMMERCE_PRODUCT_H
