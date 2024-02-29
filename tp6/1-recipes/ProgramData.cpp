#include "ProgramData.hpp"
#include "Recipe.hpp"


void ProgramData::add_material(std::string name)
{
    _inventory.emplace_back(std::make_unique<Material>( std::move (name) ));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    for (auto &material : _inventory) {
        materials.emplace_back(material.get());
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    //auto recipe = std::make_unique<Recipe>(materials, products);
    auto recipe = Recipe { materials, products };
    _recipes.emplace_back(recipe);
    std::cout << "Recipe " << recipe << "has been registered" << std::endl;
}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{
    for (const auto& recipe : _recipes) {
        for (const auto& material : recipe.getMaterials()) {
            for (auto &inInventory : _inventory) {
                if (inInventory.get()->getName() != material) {
                    break;
                }
            }
        }
        recipes.emplace_back(&recipe);
    }
}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    return result;
}