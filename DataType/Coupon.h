//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_COUPON_H
#define E_COMMERCE_COUPON_H

#include <string>
#include <cstdint>

namespace DataType {

    class Coupon {
    public:
        enum Type {
            PERCENTAGE = 1,
            AMOUNT
        };

        static std::string typeToString(Type type);

        Coupon(std::string name, uint64_t id, Type type, double value, std::string code);

        Coupon(std::string name, Type type, double value, std::string code);

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] uint64_t getId() const;

        [[nodiscard]] Type getType() const;

        [[nodiscard]] double getValue() const;

        [[nodiscard]] std::string getCode() const;

        void setName(std::string name);

        void setId(uint64_t id);

        void setType(Type type);

        void setValue(double value);

        void setCode(std::string code);

        double apply(double price) const;

        static std::string serialize(const Coupon &coupon);

        static Coupon deserialize(const std::string &line);

    private:
        std::string name;
        uint64_t id;
        Type type;
        double value;
        std::string code;
    };

} // DataType

#endif //E_COMMERCE_COUPON_H
