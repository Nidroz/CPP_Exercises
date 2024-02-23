#pragma once

#include <iostream>
#include "Object.hpp"

class CopyablePtr {
    public:
        CopyablePtr()
            : _object { nullptr }
        {}

        CopyablePtr(int integer)
            : _object {new Object { integer } }
        {}

        bool operator==(std::nullptr_t) {
            return _object == nullptr;
        }

        Object& operator*() const {
            return *_object;
        }

        CopyablePtr& operator=(std::nullptr_t) {
            delete _object;
            _object = nullptr;
            return *this;
        }

    private:
        Object* _object = nullptr;
};