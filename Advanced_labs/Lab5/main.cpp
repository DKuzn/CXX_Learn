#include <iostream>
#include "DecimalString.h"

int main() {
    DecimalString str1 = DecimalString("+50");
    DecimalString str2 = DecimalString("-3");
    DecimalString str3 = DecimalString("234");
    std::cout << "Decimal string 1:\n" << str1 << std::endl;
    std::cout << "Decimal string 2:\n" << str2 << std::endl;
    std::cout << "Decimal string 3:\n" << str3 << std::endl;
    std::cout << "String3 - String1:\n" << (str3 - str1) << std::endl;
    std::cout << "String1 > String2:\n" << (str1 > str2) << std::endl;
    std::cout << "String1 < String2:\n" << (str1 < str2) << std::endl;
}
