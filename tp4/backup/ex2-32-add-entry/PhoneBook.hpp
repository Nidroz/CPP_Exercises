#pragma once

#include <vector>
#include <algorithm>
#include "../src/PhoneBookEntry.hpp"
#include "../src/PhoneNumber.hpp"

class PhoneBook {
    public:
        PhoneBook() {};

        bool add_entry(PhoneBookEntry newPhoneEntry) {
            _phonesBook.emplace_back(newPhoneEntry);
            return std::find(_phonesBook.begin(), _phonesBook.end(), newPhoneEntry) != _phonesBook.end();
        }

        const PhoneNumber *get_number(const std::string& name) const {
            for (auto &phoneEntry : _phonesBook) {
                if (phoneEntry.get_name() == name) {
                    return &phoneEntry.get_number();
                }
            }
            return nullptr;
        }

    private:
        std::vector<PhoneBookEntry> _phonesBook;
};