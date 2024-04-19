#pragma once

#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t Size>
class HybridArray
{
public:
    HybridArray() = default;

    constexpr static size_t static_size() { return Size; }

    T& push_back(T element)
    {
        if (_nbElems >= _array.size())
        {
            if (!copyDynamic)
            {
                for (int i = 0; i < _array.size(); i++)
                {
                    _vector.emplace_back(std::move(_array.at(i)));
                }
                copyDynamic = true;
            }
            return _vector.emplace_back(std::move(element));
        }
        return _array[_nbElems++] = element;
    }

    size_t size() const { return _vector.empty() ? _nbElems : _vector.size(); }

    T& operator[](size_t index)
    {
        if (copyDynamic)
        {
            return _vector[index];
        }
        return _array[index];
    }

    const T& operator[](size_t index) const
    {
        if (copyDynamic)
        {
            return _vector[index];
        }
        return _array[index];
    }

private:
    std::array<T, Size> _array;
    std::vector<T>      _vector {};
    size_t              _nbElems    = 0;
    bool                copyDynamic = false;
};


template <typename T>
class HybridArray<T, 0u> : public std::vector<T>
{
    using std::vector<T>::vector;
};