#pragma once

#include <ostream>
#include <string>
#include <iostream>

class Material
{
    public:
        Material(const std::string& name)
            : _name { std::move(name) }
        {
            std::cout << _name << " was created" << std::endl;
        }

        ~Material() {
            std::cout << _name << " was destroyed" << std::endl;
        }

        const std::string& getName() const {
            return _name;
        }

        // Affiche le nom d'un materiau.
        friend std::ostream& operator<<(std::ostream& stream, const Material& material) { 
            return stream << material._name; 
        }


    private:
        std::string _name;
};
