#include <iostream>
#include "Person.hpp"

int main(int argc, char **argv) {
    Person person = {"Palluche","La Faluche"};
    std::cout << "La personne s'appelle " << person.get_firstname() << " " << person.get_surname() << std::endl;
}