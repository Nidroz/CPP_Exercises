#pragma once

#include <iostream>
#include <vector>

class PhoneNumber {
    public:
        PhoneNumber(int nb1, int nb2, int nb3, int nb4, int nb5)
            : _nb1 { nb1 }
            , _nb2 { nb2 }
            , _nb3 { nb3 }
            , _nb4 { nb4 }
            , _nb5 { nb5 }
        {
            numbers.emplace_back(_nb1);
            numbers.emplace_back(_nb2);
            numbers.emplace_back(_nb3);
            numbers.emplace_back(_nb4);
            numbers.emplace_back(_nb5);
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
            return numbers[index];
        }

    private:
        int _nb1 = 0;
        int _nb2 = 0;
        int _nb3 = 0;
        int _nb4 = 0;
        int _nb5 = 0;
        std::vector<int> numbers;
};