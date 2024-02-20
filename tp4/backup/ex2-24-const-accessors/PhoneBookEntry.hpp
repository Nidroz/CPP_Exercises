#pragma once

#include <iostream>
#include <string>
#include "PhoneNumber.hpp"

class PhoneBookEntry {
    public:
        PhoneBookEntry(const std::string& name, const PhoneNumber& phoneNumber)
            : _name { name }
            , _phoneNumber { phoneNumber }
        {}

        const std::string& get_name() const {
            return _name;
        }

        const PhoneNumber& get_number() const {
            return _phoneNumber;
        }

        bool operator==(const PhoneBookEntry& other) const {
            return _name == other._name;
        }

    private:
        std::string _name;
        PhoneNumber _phoneNumber;
};