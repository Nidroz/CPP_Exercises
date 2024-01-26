#include <iostream>
#include <string>
#include "Card.hpp"

int main(int argc, char const *argv[]) {
    const Card c1 { 8, "Pique" };
    c1.print();

    Card c2 { 8, "Carreau" };
    std::cout << (c2 == c1) << std::endl; // -> 1
    Card c3 { 10, "Carreau" };
    std::cout << (c2 == c3) << std::endl; // -> 0 
    return 0;
}
