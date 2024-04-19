#pragma once

#include "Base.hpp"

class DerivedInt : public Base {
    public:
        DerivedInt() = default;

        DerivedInt(int data)
            : _data { data }
            , Base("Int")
        {}

        int data() const {
            return _data;
        }

        bool is_null() const override {
            return _data == 0;
        }

        std::string to_string() const override {
            return std::to_string(_data);
        }
    
    protected:
        bool withSameTypeIsEqual(const Base& base) const override {
            return dynamic_cast<const DerivedInt&>(base)._data == _data;
        }

    private:
        int _data = 0;
};