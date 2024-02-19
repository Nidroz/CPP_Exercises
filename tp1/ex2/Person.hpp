#pragma once

#include <string>

class Person
{
public:
    Person(const std::string& firstName, const std::string& lastName);

    const std::string& getFirstName() const;

    const std::string& getSurname() const;

private:
    std::string first_name;
    std::string surname;
};