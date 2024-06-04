//
// Created by chi on 24/05/12.
//

#include <sstream>
#include "Coupon.h"

namespace DataType {

    Coupon::Coupon(std::string name, uint64_t id, Coupon::Type type, double value, std::string code)
            : name(std::move(name)), id(id), type(type), value(value), code(std::move(code)) {
    }

    Coupon::Coupon(std::string name, DataType::Coupon::Type type, double value, std::string code)
            : name(std::move(name)), id(), type(type), value(value), code(std::move(code)) {
    }

    uint64_t Coupon::getId() const {
        return id;
    }

    Coupon::Type Coupon::getType() const {
        return type;
    }

    double Coupon::getValue() const {
        return value;
    }

    std::string Coupon::getCode() const {
        return code;
    }

    std::string Coupon::serialize(const Coupon &coupon) {
        // 采用CSV格式，分别为名称、ID、类型、值、代码
        return coupon.getName() + ',' + std::to_string(coupon.getId()) + ',' +
               std::to_string(coupon.getType()) + ',' +
               std::to_string(coupon.getValue()) + ',' + coupon.getCode();
    }

    Coupon Coupon::deserialize(const std::string &line) {
        std::istringstream iss(line);
        std::string name, id, type, value, code;
        std::getline(iss, name, ',');
        std::getline(iss, id, ',');
        std::getline(iss, type, ',');
        std::getline(iss, value, ',');
        std::getline(iss, code, ',');
        return {name,
                std::stoull(id),
                static_cast<Coupon::Type>(std::stoul(type)),
                std::stod(value),
                code};
    }

    std::string Coupon::typeToString(Coupon::Type type) {
        const std::string typeString[] = {"PERCENTAGE", "AMOUNT"};
        if (type > 2 || type < 1) {
            throw std::invalid_argument("Invalid type");
        }
        return typeString[type - 1];
    }

    void Coupon::setId(uint64_t id) {
        this->id = id;
    }

    void Coupon::setType(Coupon::Type type) {
        this->type = type;
    }

    void Coupon::setValue(double value) {
        this->value = value;
    }

    void Coupon::setCode(std::string code) {
        this->code = std::move(code);
    }

    double Coupon::apply(double price) const {
        double result = price;
        switch (type) {
            case PERCENTAGE:
                result = price * (1 - value);
                break;
            case AMOUNT:
                result = price - value;
                break;
            default:
                throw std::invalid_argument("Invalid type");
        }
        // 防止折扣后价格为负数
        if (result < 0) {
            result = 0.01;
        }
        return result;
    }

    std::string Coupon::getName() const {
        return name;
    }

    void Coupon::setName(std::string name) {
        this->name = std::move(name);
    }
} // DataType