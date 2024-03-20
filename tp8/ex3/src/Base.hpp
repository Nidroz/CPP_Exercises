#pragma once

#include <ostream>
#include <string>

class Base {
    public:
        Base() = default;

        Base(const std::string& type)
            : _type { type }
        {}

        virtual bool is_null() const = 0;

        virtual std::string to_string() const = 0;

        std::string type() const {
            return _type;
        }

        friend std::ostream& operator<<(std::ostream& stream, const Base& base) {
            return stream << base.to_string();
        }

        bool operator==(const Base& other) {
            if (this->type() != other.type()) {
                return false;
            }
            return is_same_value_with_assuming_same_type(other);
        }

    protected:
        virtual bool is_same_value_with_assuming_same_type(const Base& base) const = 0;

    private:
        std::string _type;
};