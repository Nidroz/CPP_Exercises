#pragma once

#include <iostream>
#include <list>
#include "PhoneBookEntry.hpp"

class PhoneBook {
    public:
        PhoneBook() {}

        void add_entry(const PhoneBookEntry& phoneEntry) {
            _phoneEntries.push_back(phoneEntry);
        }

        const PhoneNumber* get_number(const std::string& name) const {
            for (auto &phoneEntry : _phoneEntries) {
                if (phoneEntry.get_name() == name) {
                    return &phoneEntry.get_number();
                }
            }
            return nullptr;
        }
    
    private:
        std::list<PhoneBookEntry> _phoneEntries;
};