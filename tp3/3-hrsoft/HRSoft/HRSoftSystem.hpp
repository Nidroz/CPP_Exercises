#pragma once

#include "Department.hpp"

#include <list>
#include <string>

class HRSoftSystem
{
public:
    Department &add_department(const std::string &name)
    {
        return _departments.emplace_back(name);
    }

    void print_all_departments()
    {
        std::cout << "ALL DEPARTMENTS : " << std::endl;
        for (auto department : _departments)
        {
            std::cout << "- " << department << std::endl;
        }
        std::cout << std::endl;
    }

    void print_all_employees()
    {
        std::cout << "ALL EMPLOYEES : " << std::endl;
        for (auto department : _departments)
        {
            department.print_employees();
        }
        std::cout << std::endl;
    }

    void remove_employee(Employee &employee)
    {
        std::cout << "\nREMOVING THE EMPLOYEE: " << employee << std::endl;
        for (auto &department : _departments)
        {
            department.remove_employee(employee);
            // department.print_employees();
        }
    }

    Department *find_department(const std::string &name)
    {
        for (auto &department : _departments)
        {
            if (department.get_name() == name)
            {
                std::cout << "FOUNDED !" << std::endl;
                return &department;
            }
        }
        // si employé (ou manager) pas trouver, on l'ajoute
        return nullptr;
    }

    Employee *find_employee(const std::string &name)
    {
        for (auto &department : _departments)
        {
            for (auto &employee : department.get_employees())
            {
                if (employee.get_name() == name)
                {
                    return &employee;
                }
            }
        }
        return nullptr;
    }

private:
    std::list<Department> _departments;
};
