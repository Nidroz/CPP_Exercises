#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include "PhoneBookEntry.hpp"

class PhoneBook {
    public:
        PhoneBook() {}

        bool add_entry(const PhoneBookEntry& phoneEntry) {
            bool contains = std::find(_phoneEntries.begin(), _phoneEntries.end(), phoneEntry) != _phoneEntries.end();
            if (phoneEntry.get_number().is_valid() && !contains) {   
                _phoneEntries.push_back(phoneEntry);
                return true;
            }
            return false;
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