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

        Coupon(uint64_t id, Type type, double value, std::string code);

        Coupon(Type type, double value, std::string code);

        [[nodiscard]] uint64_t getId() const;

        [[nodiscard]] Type getType() const;

        [[nodiscard]] double getValue() const;

        [[nodiscard]] std::string getCode() const;

        void setId(uint64_t id);

        void setType(Type type);

        void setValue(double value);

        void setCode(std::string code);

        static std::string serialize(const Coupon &coupon);

        static Coupon deserialize(const std::string &line);

    private:
        uint64_t id;
        Type type;
        double value;
        std::string code;
    };

} // DataType

#endif //E_COMMERCE_COUPON_H
