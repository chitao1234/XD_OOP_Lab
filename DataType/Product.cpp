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
                     long remainingStock) : id(id),
                                            name(std::move(name)),
                                            description(std::move(description)),
                                            price(price),
                                            remainingStock(remainingStock),
                                            discount(1) {}

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
        std::ostringstream oss;
        oss << product.getId() << ',';
        oss << product.getName() << ',';
        oss << product.getDescription() << ',';
        oss << product.getPrice() << ',';
        oss << product.getRemainingStock() << ',';
        oss << product.getDiscount();
        return oss.str();
    }

    Product Product::deserialize(const std::string &line) {
        std::istringstream iss(line);
        std::string id, name, description, price, remainingStock, discount;
        std::getline(iss, id, ',');
        std::getline(iss, name, ',');
        std::getline(iss, description, ',');
        std::getline(iss, price, ',');
        std::getline(iss, remainingStock, ',');
        std::getline(iss, discount, ',');
        Product product = {std::stoul(id),
                           name,
                           description,
                           std::stod(price),
                           std::stol(remainingStock)};
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
               discount == product.discount;
    }

    double Product::getDiscount() const {
        return discount;
    }

    void Product::setDiscount(double discount) {
        this->discount = discount;
    }
}
