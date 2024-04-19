#pragma once

#include <string>
#include "Base.hpp"

class DerivedString : public Base {
    public:
        DerivedString() = default;

        DerivedString(std::string data)
            : _data { std::move(data) }
            , Base("String")
        {}

        const std::string& data() const {
            return _data;
        }

        bool is_null() const override {
            return _data == "";
        }

        std::string to_string() const override {
            return _data;
        }

    protected:
        bool withSameTypeIsEqual(const Base& base) const override {
            return dynamic_cast<const DerivedString&>(base)._data == _data;
        }

    private:
        std::string _data;
};