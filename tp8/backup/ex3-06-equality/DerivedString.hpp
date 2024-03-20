#pragma once

#include "Base.hpp"
#include <string>

class DerivedString : public Base {
    public:
        DerivedString(const std::string& data)
            : Base("String")
            , _data { data }
        {}

        const std::string& data() const {
            return _data;
        }

        bool is_null() const override {
            return _data == "";
        }

        std::string to_string() const {
            return _data;
        }

    protected:
        bool is_same_value_with_assuming_same_type(const Base& base) const override {
            return (dynamic_cast<const DerivedString&>(base)._data == _data);
        }

    private:
        std::string _data;
};