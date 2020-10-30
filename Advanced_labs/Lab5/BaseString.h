#ifndef CXX_LEARN_BASESTRING_H
#define CXX_LEARN_BASESTRING_H
#include <string>


class BaseString {
public:
    std::string value;
    BaseString();
    explicit BaseString(std::string value_i);
    explicit BaseString(char value_i);
    ushort getByteLength() const;
    void clear();
    friend std::ostream &operator<<(std::ostream &out, const BaseString &bs);

protected:
    ushort byteLength;
};


#endif //CXX_LEARN_BASESTRING_H
