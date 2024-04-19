#pragma once

#include <ostream>

class Base {
    public:
        Base() = default;

        Base(std::string type)
            : _type { std::move(type) }
        {}

        virtual bool is_null() const = 0;

        std::string type() const {
            return _type;
        }

        bool operator==(const Base& other) const {
            if (_type != other._type) {
                return false;
            }
            return withSameTypeIsEqual(other);
        }

        virtual std::string to_string() const = 0;

        friend std::ostream& operator<<(std::ostream& stream, const Base& base) {
            return stream << base.to_string();
        }

    protected:
        virtual bool withSameTypeIsEqual(const Base& base) const = 0;

    private:
        std::string _type {""};
};