#include "Card.hpp"
#include <iostream>
#include <string>

Card::Card(unsigned int value, const std::string& color)
    : _value { value }
    , _color { color }
    {}

void Card::print() const {
    switch (_value) {
    case 11:
        std::cout << "Valet de " << _color << std::endl;
        break;
    case 12:
        std::cout << "Dame de " << _color << std::endl;
        break;
    case 13:
        std::cout << "Roi de " << _color << std::endl;
        break;
    case 14:
        std::cout << "As de " << _color << std::endl;
        break;
    
    default:
        std::cout << _value << " de " << _color << std::endl;
        break;
    }
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