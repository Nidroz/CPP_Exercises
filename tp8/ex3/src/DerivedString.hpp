#pragma once

#include "Base.hpp"

class DerivedString : public Base {
    public:
        DerivedString(const std::string& str)
           : _str { str }
        {}

        std::string data() const {
            return _str;
        }

        bool is_null() const override {
            return _str == "";
        };

        std::string type() const override {
            return "String";
        }

        // operator<<
        friend std::ostream& operator<<(std::ostream& stream, const DerivedString& derivedString) {
            return stream << derivedString._str;
        }

    private:
        std::string _str;
};