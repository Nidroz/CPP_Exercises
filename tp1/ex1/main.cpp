#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Entre ton nom: "; // affiche le message

    std::string name;
    std::cin >> name; // demande le 'name' with 20 caracters field
    std::cout << "Bonjour " << name << " !" << std::endl; // affiche message bonjour...

    return 0;
}
