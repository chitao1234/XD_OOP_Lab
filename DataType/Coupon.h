//
// Created by chi on 24/05/12.
//

#ifndef E_COMMERCE_COUPON_H
#define E_COMMERCE_COUPON_H

#include <string>
#include <cstdint>

namespace DataType {
    // 优惠券类
    class Coupon {
    public:
        // 分为百分比折扣和金额折扣两种类型
        enum Type {
            PERCENTAGE = 1,
            AMOUNT
        };

        // 用于打印输出
        static std::string typeToString(Type type);

        // 用于从文件中读取
        Coupon(std::string name, uint64_t id, Type type, double value, std::string code);

        // 用于创建新的优惠券
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

        // 应用优惠券，返回折扣后的价格
        [[nodiscard]] double apply(double price) const;

        // 序列化优惠券，用于保存到文件
        static std::string serialize(const Coupon &coupon);

        // 反序列化优惠券，用于从文件中读取
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
