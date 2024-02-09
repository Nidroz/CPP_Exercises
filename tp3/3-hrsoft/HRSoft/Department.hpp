#pragma once

#include "Employee.hpp"

#include <list>
#include <string>
#include <iostream>

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

    friend std::ostream &operator<<(std::ostream &, const Department &);

    void print_employees()
    {
        std::cout << "EMPLOYEES (of " << _name << " department) : " << std::endl;
        for (const auto &employee : _employees)
        {
            std::cout << employee << std::endl;
        }
        std::cout << std::endl;
    }

    void remove_employee(Employee &employee)
    {
        for (auto &employi : _employees)
        {
            employi.remove_subordinate(employee);
        }
        _employees.remove(employee);
    }

    const std::string &get_name() const
    {
        return _name;
    }

    std::list<Employee> get_employees() const
    {
        return _employees;
    }

    void print_employees_by_department_name(const std::string &name)
    {
        if (name == _name)
        {
            for (auto employee : _employees)
            {
                std::cout << employee << std::endl;
            }
        }
    }

private:
    std::string _name;
    std::list<Employee> _employees;
};

inline std::ostream &operator<<(std::ostream &stream, const Department &department)
{
    return stream << "DEPARTMENT : " << department._name;
}
