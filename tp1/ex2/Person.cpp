#include <iostream>
#include <string>
#include "Person.hpp"

Person::Person(const std::string& firstName, const std::string& lastName)
    : first_name { firstName }
    , surname { lastName }
{}

const std::string& Person::getFirstName() const {
    return first_name;
}

const std::string& Person::getSurname() const {
    return surname;
}
