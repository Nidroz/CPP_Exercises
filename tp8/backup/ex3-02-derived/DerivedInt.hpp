#pragma once

#include "Base.hpp"

class DerivedInt : public Base {
    public:
        DerivedInt(int data)
            : Base()
            , _data { data }
        {}

        int data() const {
            return _data;
        }

        bool is_null() const {
            return _data == 0;
        }

    private:
        int _data;
};