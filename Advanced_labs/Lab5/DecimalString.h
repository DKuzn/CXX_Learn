#ifndef CXX_LEARN_DECIMALSTRING_H
#define CXX_LEARN_DECIMALSTRING_H
#include "BaseString.h"


class DecimalString: public BaseString {
public:
    explicit DecimalString(const std::string& temp);
    friend DecimalString operator-(DecimalString &str1, DecimalString &str2);
    friend bool operator>(DecimalString &str1, DecimalString &str2);
    friend bool operator<(DecimalString &str1, DecimalString &str2);
};


#endif //CXX_LEARN_DECIMALSTRING_H
