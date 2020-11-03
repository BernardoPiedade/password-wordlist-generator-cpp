#include <iostream>
#include <string>
#include <algorithm>


// Change word to upper case
std::string word_toUpper(std::string s)
{
    std::for_each(s.begin(), s.end(), [](char & c)
    {
        c = ::toupper(c);
    });

    return s;
}

// Change word to lower case
std::string word_toLower(std::string s)
{
    std::for_each(s.begin(), s.end(), [](char & c)
    {
        c = ::tolower(c);
    });

    return s;
}

// Check if the word is the same

bool is_word_same(std::string s, std::string s2)
{
    std::for_each(s.begin(), s.end(), [](char & c)
    {
        c = ::tolower(c);
    });

    std::for_each(s2.begin(), s2.end(), [](char & c)
    {
        c = ::tolower(c);
    });

    if(s == s2)
        return true;

    return false;
}
