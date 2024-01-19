#include <string>

class Person
{
    public:
        Person();
        Person(std::string first_name, std::string surname);
        std::string get_firstname();
        std::string get_surname();

    private:
        std::string _first_name;
        std::string _surname;
};