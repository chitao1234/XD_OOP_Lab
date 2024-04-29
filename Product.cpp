//
// Created by chi on 24/04/28.
//

#include <sstream>
#include "Product.h"

Product::Product(int id, std::string name, std::string description, double price) : id(id), name(std::move(name)),
                                                                                    description(std::move(description)),
                                                                                    price(price) {}

int Product::getId() const {
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
    return oss.str();
}

Product Product::deserialize(const std::string &line) {
    std::istringstream iss(line);
    std::string id, name, description, price;
    std::getline(iss, id, ',');
    std::getline(iss, name, ',');
    std::getline(iss, description, ',');
    std::getline(iss, price, ',');
    return {std::stoi(id), name, description, std::stod(price)};
}
