#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

std::string toUpperString(std::string str) {
    std::transform(str.cbegin(), str.cend(), str.begin(), 
        [](unsigned char c) { return std::toupper(c); });
    return str;
}

std::string concat_in_caps(const std::vector<std::string>& words)
{
    // std::accumulate(...);
    return std::accumulate(words.begin(), words.end(), std::string {},
     [](const std::string& word, const std::string& otherWord) { 
        if (word.empty()) { return toUpperString(otherWord); } 
     return toUpperString(word) + " " + toUpperString(otherWord); });
}

int main()
{
    std::vector<std::string> words { "ARRETE", "De", "criEr", "steuplAIt" };
    std::cout << concat_in_caps(words) << std::endl;
    return 0;
}

