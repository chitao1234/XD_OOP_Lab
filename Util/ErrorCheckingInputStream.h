//
// Created by chi on 24/05/27.
//

#ifndef E_COMMERCE_ERRORCHECKINGINPUTSTREAM_H
#define E_COMMERCE_ERRORCHECKINGINPUTSTREAM_H

#include <iostream>

namespace Util {

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
    private:
        std::istream &stream;
    };

    template<typename T>
    ErrorCheckingInputStream &ErrorCheckingInputStream::operator>>(T &value) {
        stream >> value;
        while (fail()) {
            std::cout << "Invalid input. Please try again: ";
            stream.clear();
            stream.ignore();
            stream >> value;
        }
        return *this;
    }

    extern ErrorCheckingInputStream cinWrapper;

} // Util

#endif //E_COMMERCE_ERRORCHECKINGINPUTSTREAM_H
