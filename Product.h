//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_PRODUCT_H
#define E_COMMERCE_PRODUCT_H

#include <string>
#include <cstdint>

class Product {
public:
    Product(uint64_t id, std::string name, std::string description, double price, long remainingStock);

    [[nodiscard]] uint64_t getId() const;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] std::string getDescription() const;

    [[nodiscard]] double getPrice() const;

    [[nodiscard]] long getRemainingStock() const;

    void setName(std::string name);

    void setDescription(std::string description);

    void setPrice(double price);

    void setRemainingStock(long remainingStock);

    static std::string serialize(const Product &product);

    static Product deserialize(const std::string &line);

private:
    uint64_t id;
    std::string name;
    std::string description;
    double price;
    long remainingStock;
};

#endif //E_COMMERCE_PRODUCT_H
