#pragma once

#include <iostream>
#include "Object.hpp"

class CopyablePtr {
    public:
        CopyablePtr() = default;

        CopyablePtr(int value)
            : _object { new Object(value) }
        {}

        bool operator==(std::nullptr_t other) const {
            return _object == nullptr;
        }

        Object& operator*() const {
            return *_object;
        }

        CopyablePtr& operator=(std::nullptr_t ) {
            delete _object;
            _object = nullptr;
            return *this;
        }

    private:
        Object* _object = nullptr;
};