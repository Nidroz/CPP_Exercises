#pragma once

#include <iostream>
#include "Object.hpp"

class CopyablePtr {
    public:
        CopyablePtr() 
            : _object { nullptr }
        {}

        CopyablePtr(int value)
            : _object { new Object(value) }
        {}

        CopyablePtr(const CopyablePtr& other)
            : _object { other._object == nullptr ? nullptr : new Object(*other._object) }
        {}

        CopyablePtr(CopyablePtr&& other)
            : _object { std::move(other._object) }
        {
            other._object = nullptr;
        }

        ~CopyablePtr() {
            //delete _object;
        }


        bool operator==(std::nullptr_t) const {
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

        CopyablePtr& operator=(const CopyablePtr& other) {
            if (this != &other) {
                delete _object;
                CopyablePtr copy { other };
                _object = copy._object;
            }
            return *this;
        }

        CopyablePtr& operator=(CopyablePtr&& other) {
            if (this != &other) {
                delete _object;
                CopyablePtr move { std::move(other) };
                _object = move._object;
            }
            return *this;
        }

        // Bonus F
        /*
        CopyablePtr& operator=(CopyablePtr other) {
            std::swap(_object, other._object);
            return *this;
        }
        */

    private:
        Object* _object = nullptr;
};