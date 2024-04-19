#pragma once

#include <string>
#include <memory>
#include "../lib/InstanceCounter.hpp"

class StringInstancePair {
    public:
        StringInstancePair(std::string str)
            : _str { std::move(str) }
            , _instanceCounter { std::make_unique<InstanceCounter>() }
        {}

        StringInstancePair(const StringInstancePair& other)
            : _str { other._str }
            , _instanceCounter { std::make_unique<InstanceCounter>(other.get_instance_counter()) }
        {}

        StringInstancePair(StringInstancePair&& other) = default;

        const std::string& get_str() const {
            return _str;
        }

        const InstanceCounter& get_instance_counter() const {
            return *_instanceCounter;
        }
        
    private:
        std::string _str;
        std::unique_ptr<InstanceCounter> _instanceCounter;
        //InstanceCounter _instanceCounter;
};