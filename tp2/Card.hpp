#pragma once

#include <string>

enum class CardValue {
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 1
};

enum class CardColor {
    HEARTS = 0,
    DIAMONDS = 1,
    CLUBS = 2,
    SPADES = 3
};

class Card
{
public:
    Card(unsigned int value, const std::string& color);
    void print() const;
    bool operator==(Card other) const;
    bool operator<(Card other) const;
    friend std::ostream& operator<<(std::ostream& stream, Card card);
    
private:
    unsigned int _value;
    std::string _color;
};