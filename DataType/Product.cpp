//
// Created by chi on 24/04/28.
//

#include <sstream>
#include "Product.h"

namespace DataType {
    Product::Product(uint64_t id,
                     std::string name,
                     std::string description,
                     double price,
                     long remainingStock,
                     uint64_t categoryId)
            : id(id),
              name(std::move(name)),
              description(std::move(description)),
              price(price),
              remainingStock(remainingStock),
              discount(1),
              categoryId(categoryId) {}

    uint64_t Product::getId() const {
        return id;
    }

    std::string Product::getName() const {
        return name;
    }

    std::string Product::getDescription() const {
        return description;
    }

    double Product::getPrice() const {
        return price;
    }

    double Product::getActualPrice() const {
        return price * discount;
    }

    void Product::setName(std::string name) {
        this->name = std::move(name);
    }

    void Product::setDescription(std::string description) {
        this->description = std::move(description);
    }

    void Product::setPrice(double price) {
        this->price = price;
    }

    std::string Product::serialize(const Product &product) {
        // 采用CSV逗号分隔的方式序列化商品，分别为商品号、名称、描述、价格、库存、折扣、分类号
        std::ostringstream oss;
        oss << product.getId() << ',';
        oss << product.getName() << ',';
        oss << product.getDescription() << ',';
        oss << product.getPrice() << ',';
        oss << product.getRemainingStock() << ',';
        oss << product.getDiscount() << ',';
        oss << product.getCategoryId();
        return oss.str();
    }

    Product Product::deserialize(const std::string &line) {
        std::istringstream iss(line);
        std::string id, name, description, price, remainingStock, discount, categoryId;
        std::getline(iss, id, ',');
        std::getline(iss, name, ',');
        std::getline(iss, description, ',');
        std::getline(iss, price, ',');
        std::getline(iss, remainingStock, ',');
        std::getline(iss, discount, ',');
        std::getline(iss, categoryId, ',');
        Product product = {std::stoull(id),
                           name,
                           description,
                           std::stod(price),
                           std::stol(remainingStock),
                           std::stoull(categoryId)};
        product.setDiscount(std::stod(discount));
        return product;
    }

    long Product::getRemainingStock() const {
        return remainingStock;
    }

    void Product::setRemainingStock(long remainingStock) {
        this->remainingStock = remainingStock;
    }

    bool Product::operator==(const Product &product) const {
        return id == product.id && name == product.name && description == product.description &&
               price == product.price &&
               remainingStock == product.remainingStock &&
               discount == product.discount &&
               categoryId == product.categoryId;
    }

    double Product::getDiscount() const {
        return discount;
    }

    void Product::setDiscount(double discount) {
        this->discount = discount;
    }

    uint64_t Product::getCategoryId() const {
        return categoryId;
    }

    void Product::setCategoryId(uint64_t categoryId) {
        this->categoryId = categoryId;
    }
}
