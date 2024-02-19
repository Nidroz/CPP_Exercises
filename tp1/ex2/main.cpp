#include <iostream>
#include <vector>
#include "Person.hpp"

int main(int argc, char const *argv[])
{
    Person person{"Palluche", "La Faluche"};
    std::vector<Person> persons;
    int nbPers = 0;

    std::cout << "Nombre de personnes: ";
    std::cin >> nbPers;

    for (int i = 0; i < nbPers; i++) {
        std::string prenom;
        std::string nom;
        std::cout << "Prenom: ";
        std::cin >> prenom;
        std::cout << "Nom: ";
        std::cin >> nom;
        persons.emplace_back(Person { prenom , nom });
    }

    std::cout << "Les personnes sont ";
    for (const auto& pers : persons) {
        std::cout << pers.getFirstName() << " " << pers.getSurname() << ", ";
    }
    return 0;
}
