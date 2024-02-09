#include <iostream>
#include "PhoneNumber.hpp"

int main() {
    auto pn = PhoneNumber { 1, 64, 0, 66, 73 };
    std::cout << pn;
    return 0;
}