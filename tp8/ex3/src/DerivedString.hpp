#pragma once

<<<<<<< HEAD
#include <string>
#include "Base.hpp"

class DerivedString : public Base {
    public:
        DerivedString() = default;

        DerivedString(std::string data)
            : _data { std::move(data) }
            , Base("String")
=======
#include "Base.hpp"
#include <string>

class DerivedString : public Base {
    public:
        DerivedString(const std::string& data)
            : Base("String")
            , _data { data }
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
        {}

        const std::string& data() const {
            return _data;
        }

        bool is_null() const override {
            return _data == "";
        }

<<<<<<< HEAD
        std::string to_string() const override {
=======
        std::string to_string() const {
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
            return _data;
        }

    protected:
<<<<<<< HEAD
        bool withSameTypeIsEqual(const Base& base) const override {
            return dynamic_cast<const DerivedString&>(base)._data == _data;
=======
        bool is_same_value_with_assuming_same_type(const Base& base) const override {
            return (dynamic_cast<const DerivedString&>(base)._data == _data);
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
        }

    private:
        std::string _data;
};