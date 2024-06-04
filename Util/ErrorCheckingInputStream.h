//
// Created by chi on 24/05/27.
//

#ifndef E_COMMERCE_ERRORCHECKINGINPUTSTREAM_H
#define E_COMMERCE_ERRORCHECKINGINPUTSTREAM_H

#include <iostream>

namespace Util {
    // 错误检查输入流，用于对非法输入进行自动处理重试，避免程序崩溃，提高用户体验
    // 使用了装饰器模式，对输入流进行了包装
    class ErrorCheckingInputStream : public std::istream {
    public:
        explicit ErrorCheckingInputStream(std::istream &stream);

        template<typename T>
        ErrorCheckingInputStream &operator>>(T &value);

        bool good();

        bool fail();

        bool bad();

        bool eof();

        bool operator!();

        ErrorCheckingInputStream &ignore(int count = 1, int delim = EOF);

    private:
        std::istream &stream;
    };

    // 通用输入操作实现，底层所有的支持的类型都会被正确转发到对应的实现，使用模板
    template<typename T>
    ErrorCheckingInputStream &ErrorCheckingInputStream::operator>>(T &value) {
        stream >> value;
        while (fail()) {
            std::cout << "Invalid input. Please try again: ";
            stream.clear();
            stream.ignore(256, '\n');
            stream >> value;
        }
        return *this;
    }

    // 全局输入流包装器，用于替换标准输入流
    extern ErrorCheckingInputStream cinWrapper;

} // Util

#endif //E_COMMERCE_ERRORCHECKINGINPUTSTREAM_H
