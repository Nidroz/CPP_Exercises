#pragma once

#include <iostream>

template<typename T, size_t Size>
class HybridArray {
    public:
        constexpr static size_t static_size() {
            return Size;
        }
};