#pragma once

#include <ostream>

class Base {
    public:
        virtual bool is_null() const = 0;
        virtual std::string type() const = 0;
        bool operator==(const Base& other) const {
            return type() == other.type();
        }

    friend std::ostream& operator<<(std::ostream& stream, const Base& base) {
        return stream << base.type();
    }
};