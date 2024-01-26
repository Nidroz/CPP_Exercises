#include "Card.hpp"
#include <iostream>
#include <string>

Card::Card(unsigned int value, const std::string& color)
    : _value { value }
    , _color { color }
    {}

void Card::print() const {
    std::cout << _value << " de " << _color << std::endl;
}

int Card::operator==(Card other) {
    if (_value == other._value) {
        return 1;
    } 
    return 0;
}