#pragma once

#include <ostream>
<<<<<<< HEAD
=======
#include <string>
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e

class Base {
    public:
        Base() = default;

<<<<<<< HEAD
        Base(std::string type)
            : _type { std::move(type) }
=======
        Base(const std::string& type)
            : _type { type }
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
        {}

        virtual bool is_null() const = 0;

<<<<<<< HEAD
=======
        virtual std::string to_string() const = 0;

>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
        std::string type() const {
            return _type;
        }

<<<<<<< HEAD
        bool operator==(const Base& other) const {
            if (_type != other._type) {
                return false;
            }
            return withSameTypeIsEqual(other);
        }

        virtual std::string to_string() const = 0;

=======
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
        friend std::ostream& operator<<(std::ostream& stream, const Base& base) {
            return stream << base.to_string();
        }

<<<<<<< HEAD
    protected:
        virtual bool withSameTypeIsEqual(const Base& base) const = 0;

    private:
        std::string _type {""};
=======
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
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
};