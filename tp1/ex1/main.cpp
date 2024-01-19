#include <iomanip>
#include <iostream>

int main()
{
    std::cout << "Entre ton nom: "; // affiche le message

    char name[20] = ""; // chaine de characères de taille 20
    std::cin >> std::setw(20) >> name; // demande le 'name' with 20 caracters field
    std::cout << "Bonjour " << name << " !" << std::endl; // affiche message bonjour...

    return 0;
}
