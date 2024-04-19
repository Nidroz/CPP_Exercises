#pragma once

#include <string>
#include <memory>

class StringInstancePair {
    public:
<<<<<<< HEAD
        StringInstancePair() = default;

        StringInstancePair(std::string str)
            : _str { std::move(str) }
            , _instanceCounter { std::make_unique<InstanceCounter>() }
        {}

        StringInstancePair(const StringInstancePair& other)
            : _str { other._str }
            , _instanceCounter { std::make_unique<InstanceCounter>(other.get_instance_counter()) }
=======
        StringInstancePair(const std::string& data)
            : _data { data }
            , _instance { std::make_unique<InstanceCounter>() }
        {}

        StringInstancePair(const StringInstancePair& other)
            : _data { other._data }
            , _instance { std::make_unique<InstanceCounter>(*other._instance) }
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
        {}

        StringInstancePair(StringInstancePair&& other) = default;

        const std::string& get_str() const {
<<<<<<< HEAD
            return _str;
        }

        InstanceCounter& get_instance_counter() const {
            return *_instanceCounter;
        }

    private:
        std::string _str;
        std::unique_ptr<InstanceCounter> _instanceCounter;
=======
            return _data;
        }

        const InstanceCounter& get_instance_counter() const {
            return *_instance;
        }

    private:
        std::string _data;
        std::unique_ptr<InstanceCounter> _instance;
>>>>>>> a1e5913736695fd61da28e7a78026db63a1f337e
};