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

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    return result;
}