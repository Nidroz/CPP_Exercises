#pragma once

#include <string>
#include <memory>

class StringInstancePair {
    public:
        StringInstancePair(const std::string& data)
            : _data { data }
            , _instance { std::make_unique<InstanceCounter>() }
        {}

        StringInstancePair(const StringInstancePair& other)
            : _data { other._data }
            , _instance { std::make_unique<InstanceCounter>(*other._instance) }
        {}

        StringInstancePair(StringInstancePair&& other) = default;

        const std::string& get_str() const {
            return _data;
        }

        const InstanceCounter& get_instance_counter() const {
            return *_instance;
        }

    private:
        std::string _data;
        std::unique_ptr<InstanceCounter> _instance;
};