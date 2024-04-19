#pragma once

#include "Base.hpp"
#include <sstream>

class DerivedInt : public Base {
    public:
        DerivedInt(int integer)
            : Base("Int")
            , _integer { integer }
        {}

        int data() {
            return _integer;
        }

        bool is_null() const override {
            return _integer == 0;
        }

        std::string to_string() const override {
            return std::to_string(_integer);
        }

    protected:
        bool is_equal_with_same_type(const Base& base) const override {
            return (dynamic_cast<const DerivedInt&>(base)._integer == _integer);
        }

    private:
        int _integer;
};
