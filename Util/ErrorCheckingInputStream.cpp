//
// Created by chi on 24/05/27.
//

#include "ErrorCheckingInputStream.h"

namespace Util {
    ErrorCheckingInputStream::ErrorCheckingInputStream(std::istream &stream)
            : std::istream(stream.rdbuf()), stream(stream) {}

    // 转发到底层输入流
    bool ErrorCheckingInputStream::good() {
        return stream.good();
    }

    bool ErrorCheckingInputStream::fail() {
        return stream.fail();
    }

    bool ErrorCheckingInputStream::bad() {
        return stream.bad();
    }

    bool ErrorCheckingInputStream::eof() {
        return stream.eof();
    }

    bool ErrorCheckingInputStream::operator!() {
        return stream.operator!();
    }

    ErrorCheckingInputStream &ErrorCheckingInputStream::ignore(int count, int delim) {
        stream.ignore(count, delim);
        return *this;
    }

    ErrorCheckingInputStream cinWrapper(std::cin);
} // Util