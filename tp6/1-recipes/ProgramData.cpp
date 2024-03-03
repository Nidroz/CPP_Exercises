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
    bool recipeFound = false;
    for (auto &recipe : _recipes) {
        if (recipe.getId() == recipe_id) {
            recipeFound = true;
            std::cout << "Recipe found !" << std::endl;
            result.recipe = &recipe;
            for (auto recipeMaterial : recipe.getMaterials()) {
                bool found = false;
                for (auto &material : _inventory) {
                    if (material.get()->getName() == recipeMaterial) {
                        found = true;
                        // on consommme le materiau en mettant à nullptr
                        material = nullptr;
                        break;
                    }
                }
                if (!found) {
                    result.missing_materials.emplace_back(recipeMaterial);
                }
            }
        }
    }
    if (!recipeFound) {
        result.recipe = nullptr; // recette n'existe pas
    }
    return result;
}