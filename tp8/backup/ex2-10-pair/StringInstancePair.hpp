#pragma once

#include <string>
#include <memory>
#include "../lib/InstanceCounter.hpp"

class StringInstancePair {
    public:
        StringInstancePair(std::string str)
            : _str { str }
        {}

        std::string get_str() {
            return _str;
        }

        InstanceCounter get_instance_counter() {
            return _instanceCounter;
        }
    
    private:
        std::string _str;
        //std::unique_ptr<InstanceCounter> _instanceCounter;
        InstanceCounter _instanceCounter;
};