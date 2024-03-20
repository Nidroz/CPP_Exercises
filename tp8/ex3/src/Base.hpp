#pragma once

class Base {
    public:
        Base() = default;
        
        virtual bool is_null() const = 0;
};