#include <iostream>
#include <vector>
#include <sstream>
#include "Person.hpp"

int main(int argc, char **argv) {
    std::vector<Person> persons {};
    int nb_persons = 0;
    std::cout << "Nombre de personnes: ";
    std::cin >> nb_persons;

    for (int i = 0; i < nb_persons; i++) {
        std::string firstname;
        std::string surname;
        std::cout << "Prénom: ";
        std::cin >> firstname;
        std::cout << "Nom: ";
        std::cin >> surname;
        Person person = {firstname, surname};
        persons.emplace_back(person);
    }
    std::stringstream builder;
    std::cout << "Les personnes sont ";
    for (auto person : persons)  {
        builder << person.get_firstname() << " " << person.get_surname() << ", ";
    }
    std::cout << builder.str() << std::endl;
    return 0;
}