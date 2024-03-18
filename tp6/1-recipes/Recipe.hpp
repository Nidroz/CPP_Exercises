#pragma once

#include <ostream>
#include <string>
#include <vector>

class Recipe
{
    public:
        Recipe(const std::vector<std::string>& materials, const std::vector<std::string>& products) 
            : _materials { materials }
            , _products { products }
        {
            static size_t id = 1;
            _id = id++;
        }

        size_t getId() const {
            return _id;
        }

        const std::vector<std::string>& getMaterials() const {
            return _materials;
        }

    // Affiche l'identifiant et la formule d'une recette.
    friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe) { 
        stream << "(" << recipe._id << ") ";
        for(const auto& material : recipe._materials) {
            stream << material << " ";
        }
        stream << "=> ";
        for (const auto& product : recipe._products) {
            stream << product << " ";
        }
        return stream;
    }

    private:
        std::vector<std::string> _materials;
        std::vector<std::string> _products;
        size_t _id;
};
