#include <iostream>
#include "BaseString.h"

int main() {
    BaseString str = BaseString('&');
    std::cout << str.value << std::endl;
}
