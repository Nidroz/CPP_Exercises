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

bool Card::operator==(Card other) const {
    return _value == other._value;
}

bool Card::operator<(Card other) const {
    return _value < other._value;
}

std::ostream& operator<<(std::ostream& stream, Card card) {
    stream << "(" << card._value << ", " << card._color << ")";
    return stream;
}