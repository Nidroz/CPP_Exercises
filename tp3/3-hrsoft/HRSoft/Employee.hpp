#pragma once

#include <list>
#include <ostream>
#include <string>
#include <iostream>

class Employee
{
public:
    Employee(const std::string& name, unsigned int salary)
        : _name { name }, _salary { salary }
    {}

    void add_subordinate(Employee& subordinate)
    {
        _subordinates.emplace_back(&subordinate);
    }

    friend std::ostream& operator<<(std::ostream&, const Employee&);

    void print_subordinates() {
        std::cout << "SUBORTINATES OF THE EMPLOYEE " << _name << std::endl;
        for (const auto &subordinate : _subordinates) {
            std::cout << "- " << *subordinate << std::endl;
        }
    }

    void remove_subordinate(Employee& employee) {
        _subordinates.remove(&employee);
    }

    bool operator==(const Employee& employee) const {
        return _name == employee._name;
    }

private:
    std::string _name;
    unsigned int _salary = 0;
    std::list<Employee*> _subordinates;
};

inline std::ostream& operator<<(std::ostream& stream, const Employee& employee)
{
    const auto is_manager = !employee._subordinates.empty();
    return stream << employee._name
                  << " (salary: " << employee._salary
                  << "| manager: " << (is_manager ? "yes" : "no")
                  << ")";
}
