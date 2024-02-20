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
    
    private:
        std::list<PhoneBookEntry> _phoneEntries;
};