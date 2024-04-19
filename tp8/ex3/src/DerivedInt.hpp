#pragma once

#include "Base.hpp"

class DerivedInt : public Base {
    public:
<<<<<<< HEAD
        DerivedInt() = default;

        DerivedInt(int data)
            : _data { data }
            , Base("Int")
=======
        DerivedInt(int data)
            : Base("Int")
            , _data { data }
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
        {}

        int data() const {
            return _data;
        }

        bool is_null() const override {
            return _data == 0;
        }

<<<<<<< HEAD
        std::string to_string() const override {
            return std::to_string(_data);
        }
    
    protected:
        bool withSameTypeIsEqual(const Base& base) const override {
            return dynamic_cast<const DerivedInt&>(base)._data == _data;
        }

    private:
        int _data = 0;
=======
        std::string to_string() const {
            return std::to_string(_data);
        }

    protected:
        bool is_same_value_with_assuming_same_type(const Base& base) const override {
            return (dynamic_cast<const DerivedInt&>(base)._data == _data);
        }

    private:
        int _data;
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
};