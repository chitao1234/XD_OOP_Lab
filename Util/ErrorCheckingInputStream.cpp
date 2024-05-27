//
// Created by chi on 24/05/27.
//

#include "ErrorCheckingInputStream.h"

namespace Util {
    ErrorCheckingInputStream::ErrorCheckingInputStream(std::istream &stream)
            : stream(stream) {}

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

    ErrorCheckingInputStream cinWrapper(std::cin);
} // Util