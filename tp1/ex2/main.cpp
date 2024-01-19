#include <iostream>
#include "person.hpp"

int main(int argc, char **argv) {
    Person person = {};
    person.first_name = "Palluche";
    person.surname = "La Faluche";
    std::cout << "La personne s'appelle " << person.first_name << " " << person.surname << std::endl;
}