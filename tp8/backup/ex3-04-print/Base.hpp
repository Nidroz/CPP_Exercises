#pragma once

#include <ostream>
#include <string>

class DerivedInt;
class DerivedString;

class Base {
    public:
        Base()
        : Base("None")
        {}

        Base(const std::string& type)
            : _type { type }
        {}

        virtual bool is_null() const = 0;
        const std::string& type() const {
            return _type;
        }
        bool operator==(const Base& other) const {
            if (this->type() != other.type()) {
                return false;
            }
            return is_equal_with_same_type(other);
            // ou tout simplement sans passer par cette fonction
            // return to_string() == other.to_string();
        }
        virtual std::string to_string() const = 0;

        friend std::ostream& operator<<(std::ostream& stream, const Base& instance) {
            return stream << instance.to_string();
        }
    
    protected:
        virtual bool is_equal_with_same_type(const Base& base) const = 0;

    private:
        std::string _type;
};