//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_PRODUCT_H
#define E_COMMERCE_PRODUCT_H

#include <string>

class Product {
public:
    Product(int id, std::string name, std::string description, double price);

    [[nodiscard]] int getId() const;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] std::string getDescription() const;

    [[nodiscard]] double getPrice() const;

    void setName(std::string name);

    void setDescription(std::string description);

    void setPrice(double price);

    static std::string serialize(const Product &product);

    static Product deserialize(const std::string &line);

private:
    int id;
    std::string name;
    std::string description;
    double price;
};

#endif //E_COMMERCE_PRODUCT_H
