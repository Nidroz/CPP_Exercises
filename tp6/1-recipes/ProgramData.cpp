#include "ProgramData.hpp"


void ProgramData::add_material(std::string name)
{
    _inventory.emplace_back(std::make_unique<Material>( std::move(name) ));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    for (const auto& material : _inventory) {
        materials.emplace_back(material.get());
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    Recipe recipe { materials, products };
    _recipes.emplace_back(std::make_unique<Recipe>( std::move(recipe)) );
    std::cout << "Recipe " << recipe.getId() << " has been registered" << std::endl;
}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{
    for (const auto& recipe : _recipes) {
        int materialsFound = 0;
        for (const auto& material : recipe->getMaterials()) {
            for (const auto& materialInventory : _inventory) {
                if (materialInventory.get()->getName() == material) {
                    materialsFound++;
                }
            }
        }
        if (materialsFound == recipe->getMaterials().size()) {
            recipes.emplace_back(recipe.get());
        }
          
    }
}

void ProgramData::removeMaterialFromInventory(const std::string& materialToRemove) {
    for (auto it = _inventory.begin(); it != _inventory.end(); it++) {
        if (it->get()->getName() == materialToRemove) {
            _inventory.erase(it);
            break;
        }
    }
}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    bool recipeFound = false;
    for (const auto& recipe : _recipes) {
        if (recipe.get()->getId() == recipe_id) {
            recipeFound = true;
            std::cout << "Recipe found ! " << recipe.get()->getId() << std::endl;
            result.recipe = recipe.get();
            for (const auto& recipeMaterial : recipe->getMaterials()) {
                bool found = false;
                int nbFound = 0;
                for (auto &materialInventory : _inventory) {
                    if (materialInventory.get()->getName() == recipeMaterial) {
                        std::cout << "material found !" << recipeMaterial << std::endl;
                        found = true;
                        nbFound++;
                        // consume le material
                        removeMaterialFromInventory(materialInventory.get()->getName());
                        std::cout << "mise à null !" << std::endl;
                        break;
                    }
                }
                if (!found) {
                    std::cout << recipeMaterial << "pas trouvé !" << std::endl;
                    result.missing_materials.emplace_back(recipeMaterial);
                } else if (found && (nbFound == recipe->getMaterials().size())) {
                    for (const auto& product : recipe.get()->getProducts()) {
                        add_material(product);
                    }
                }
            }
        }
    }
    if (!recipeFound) { 
        result.recipe = nullptr; 
    }
    return result;
}