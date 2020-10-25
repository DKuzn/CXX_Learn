#include "BaseString.h"
#include <utility>


BaseString::BaseString() {
    value = "";
    byteLength = value.length();
}

BaseString::BaseString(std::string value_i) {
    value = std::move(value_i);
    byteLength = value.length();
}

BaseString::BaseString(char value_i) {
    value = value_i;
    byteLength = value.length();
}

ushort BaseString::getByteLength() const {
    return byteLength;
}

void BaseString::clear() {
    value = "";
    byteLength = value.length();
}