#pragma once

#include "Base.hpp"
#include <string>

class DerivedString : public Base {
    public:
        DerivedString(const std::string& data)
            : Base()
            , _data { data }
        {}

        const std::string& data() const {
            return _data;
        }

        bool is_null() const {
            return _data == "";
        }

    private:
        std::string _data;
};