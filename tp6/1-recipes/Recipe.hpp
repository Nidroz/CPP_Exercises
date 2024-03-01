#pragma once

#include <ostream>
#include <vector>
#include <string>

class Recipe
{   
    public:
        Recipe(std::vector<std::string> materials, std::vector<std::string> products)
            : _materials (std::move(materials))
            , _products (std::move(products))
        {
            ++acutalId;
        }

        const std::vector<std::string>& getMaterials() const {
            return _materials;
        }

        size_t getId() const {
            return _id;
        }

    // Affiche l'identifiant et la formule d'une recette.
    friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe) { 
        stream << "(" << recipe._id << ") ";
        for (auto material : recipe._materials) {
            stream << material << " ";
        }
        stream << "=> ";
        for (auto product : recipe._products) {
            stream << product << " ";
        }
        return stream;
    }

    private:
        std::vector<std::string> _materials;
        std::vector<std::string> _products;
        static inline size_t acutalId = 1;
        size_t _id = acutalId;
};
