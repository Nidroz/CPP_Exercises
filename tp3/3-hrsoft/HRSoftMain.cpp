#include "HRSoft/HRSoftSystem.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::stringstream get_next_line()
{
    auto line = std::string {};
    std::getline(std::cin, line);
    return std::stringstream { line };
}

std::string parse_string(std::istream& stream)
{
    auto name = std::string {};
    stream >> name;
    return name;
}

unsigned int parse_value(std::istream& stream)
{
    auto salary = 0u;
    stream >> salary;
    return salary;
}

int main()
{
    std::cout << "Welcome in HRSoft!" << std::endl;

    auto system = HRSoftSystem {};
    auto command = ' ';
    
    while (command != 'q')
    {
        std::cout << "What do you want to do? (tap 'h' for help)" << std::endl;

        auto next_line = get_next_line();
        next_line >> command;

        switch (command)
        {
            case 'd':
                system.add_department(parse_string(next_line));
                break;
 
            case 'l':
                system.print_all_departments();
                break;

            case 'e':
                std::cout << parse_string(next_line) << std::endl;
                if (auto* dpt = system.find_department(parse_string(next_line)))
                {
                    auto name = parse_string(next_line);
                    auto salary = parse_value(next_line);
                    std::cout << "Name: " << name << " | Salary: " << salary << std::endl;
                    auto* manager = system.find_employee(parse_string(next_line));
                    if (manager != nullptr) {
                        std::cout << "Manager: " << manager->get_name() << std::endl;
                    }
                    dpt->add_employee(name, salary, manager);
                }
                break;

            case 'k':
                system.print_all_employees();
                break;

            case 'f':
                if (auto* employee = system.find_employee(parse_string(next_line)))
                {
                    system.remove_employee(*employee);
                }
                break;

            case 'n':
                std::cout << "Not implemented yet " << system.find_department(parse_string(next_line)) << std::endl;
                if (auto *dpt = system.find_department(parse_string(next_line))) {
                    auto name = parse_string(next_line);
                    std::cout << "Name: " << name << std::endl;
                    dpt->print_employees_by_department_name(name);
                }
                break;

            case 'm':
                system.print_all_managers();
                {
                const std::string manager = parse_string(next_line);
                if (!manager.empty()) {
                    std::cout << "Manager: " << manager << std::endl;
                    
                }
                }
                break;

            case 't':
                std::cout << "Not implemented yet" << std::endl;
                // ...
                break;

            case 's':
                std::cout << "Not implemented yet" << std::endl;
                // ...
                break;

            case 'r':
                std::cout << "Not implemented yet" << std::endl;
                // ...
                break;

            default:
                std::cout << "Unknown command " << command << std::endl;
                break;
        }
    }

    return 0;
}
