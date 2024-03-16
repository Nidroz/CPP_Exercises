#pragma once

#include "Base.hpp"

class DerivedInt : public Base {
    public:
        DerivedInt(int integer)
            : _integer { integer }
        {}

        int data() {
            return _integer;
        }

        bool is_null() const override {
            return _integer == 0;
        }

        std::string type() const override {
            return "Int";
        }

        // operator<<
        friend std::ostream& operator<<(std::ostream& stream, const DerivedInt& derivedInt) {
            return stream << derivedInt._integer;
        }

    private:
        int _integer;
};
