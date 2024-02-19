#include <iostream>

#include "Card.hpp"

Card::Card(unsigned int value, const std::string& color)
    : _value { value }
    , _color { color }
{}

void Card::print() const {
    switch (CardValue(_value))
    {
    case CardValue::ACE:
        std::cout << "As de ";
        break;
    case CardValue::JACK:
        std::cout << "Valet de ";
        break;
    case CardValue::QUEEN:
        std::cout << "Dame de ";
        break;
    case CardValue::KING:
        std::cout << "Roi de ";
        break;
    
    default:
        std::cout << _value << " de ";
        break;
    }
    std::cout << _color << std::endl;
}

bool Card::operator==(Card other) const {
    return _value == other._value;
}

bool Card::operator<(Card other) const {
    return _value < other._value;
}

std::ostream& operator<<(std::ostream& stream, Card card) {
    switch (CardValue(card._value))
    {
    case CardValue::ACE:
        stream << "As de ";
        break;
    case CardValue::JACK:
        stream << "Valet de ";
        break;
    case CardValue::QUEEN:
        stream << "Dame de ";
        break;
    case CardValue::KING:
        stream << "Roi de ";
        break;
    
    default:
        stream << card._value << " de ";
        break;
    }
    stream << card._color;
    return stream;
}