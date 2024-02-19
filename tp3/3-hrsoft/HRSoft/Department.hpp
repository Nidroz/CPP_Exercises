#pragma once

#include "Employee.hpp"

#include <iostream>
#include <list>
#include <string>

class Department
{
public:
    Department(const std::string &name)
        : _name{name}
    {
    }

    Employee &add_employee(const std::string &name, unsigned int salary, Employee *manager)
    {
        auto &employee = _employees.emplace_back(name, salary);

        if (manager != nullptr)
        {
            manager->add_subordinate(employee);
        }

        return employee;
    }

    void print_employees()
    {
        std::cout << "EMPLOYEES (of " << _name << " department) : " << std::endl;
        for (const auto &employee : _employees)
        {
            std::cout << "- " << employee << std::endl;
        }
        std::cout << std::endl;
    }

    void remove_employee(Employee& employeeRmv) {
        for (auto &employee : _employees) {
            employee.remove_subordinate(employeeRmv);
        }
        _employees.remove(employeeRmv);
    }

    friend std::ostream& operator<<(std::ostream&, const Department&);

private:
    std::string _name;
    std::list<Employee> _employees;
};

inline std::ostream &operator<<(std::ostream &stream, const Department &department)
{
    return stream << "DEPARTMENT: " << department._name;
}
