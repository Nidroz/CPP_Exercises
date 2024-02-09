#pragma once

#include <vector>
#include <ostream>

class PhoneNumber {
    public:
        PhoneNumber(int entier1, int entier2,
        int entier3, int entier4, int entier5)
        : _entier1 { entier1 },
          _entier2 { entier2 },
          _entier3 { entier3 },
          _entier4 { entier4 },
          _entier5 { entier5 }
        {
            numbers.emplace_back(_entier1);
            numbers.emplace_back(_entier2);
            numbers.emplace_back(_entier3);
            numbers.emplace_back(_entier4);
            numbers.emplace_back(_entier5);
        }
            
        bool is_valid() const {
            for (auto number : numbers) {
                if (number < 0 || number > 99) {
                    return false;
                }
            }
            return true;
        }

        int operator[](int index) const {
            if (index < 0 || index >= numbers.size()) {
                return -1;
            }
            return numbers.at(index);
        }

        friend std::ostream& operator<<(std::ostream& stream, PhoneNumber phoneNumber) {
            for (auto pnNumber : phoneNumber.numbers) {
                stream << pnNumber;
            }
            stream << std::endl;
            return stream;
        }
    
    private:
        int _entier1;
        int _entier2;
        int _entier3;
        int _entier4;
        int _entier5;
        std::vector<int> numbers;
};