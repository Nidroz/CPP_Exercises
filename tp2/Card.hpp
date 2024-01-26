#pragma once
#include <string>
#include <ostream>

class Card {
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