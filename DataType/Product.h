//
// Created by chi on 24/04/28.
//

#ifndef E_COMMERCE_PRODUCT_H
#define E_COMMERCE_PRODUCT_H

#include <string>
#include <cstdint>

namespace DataType {
class Product {
public:
    Product(uint64_t id, std::string name, std::string description, double price, long remainingStock);

    [[nodiscard]] uint64_t getId() const;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] std::string getDescription() const;

    [[nodiscard]] double getPrice() const;

    [[nodiscard]] long getRemainingStock() const;

    [[nodiscard]] double getDiscount() const;

    [[nodiscard]] double getActualPrice() const;

    void setName(std::string name);

    void setDescription(std::string description);

    void setPrice(double price);

    void setRemainingStock(long remainingStock);

    void setDiscount(double discount);

    static std::string serialize(const Product &product);

    static Product deserialize(const std::string &line);

    bool operator==(const Product &product) const;
private:
    uint64_t id;
    std::string name;
    std::string description;
    double price;
    long remainingStock;
    double discount;
};
}

#endif //E_COMMERCE_PRODUCT_H
