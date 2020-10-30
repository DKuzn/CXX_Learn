#include "DecimalString.h"

DecimalString::DecimalString(const std::string& value_i): BaseString() {
    std::string temp = value_i;
    bool valid;
    temp.erase(0, 1);
    if (temp.find_first_not_of("0123456789") == -1) {
        valid = true;
    }
    else {
        valid = false;
    }
    if ((value_i[0] == '+' || value_i[0] == '-' || std::isdigit(value_i[0])) && valid) {
        value = value_i;
    }
    else {
        value = "0";
    }
    byteLength = value.length();
}

DecimalString operator-(DecimalString &str1, DecimalString &str2) {
    auto value1 = std::stoi(str1.value);
    auto value2 = std::stoi(str2.value);
    auto result = value1 - value2;
    return DecimalString(std::to_string(result));
}

bool operator>(DecimalString &str1, DecimalString &str2) {
    auto value1 = std::stoi(str1.value);
    auto value2 = std::stoi(str2.value);
    bool result = value1 > value2;
    return result;
}

bool operator<(DecimalString &str1, DecimalString &str2) {
    auto value1 = std::stoi(str1.value);
    auto value2 = std::stoi(str2.value);
    bool result = value1 < value2;
    return result;
}
