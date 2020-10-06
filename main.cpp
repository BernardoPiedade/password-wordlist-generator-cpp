#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>

//vector that will hold the complete wordlist
std::vector<std::string> wordlist;

//vector to store other keywords
std::vector<std::string> keywords;

std::string n;


void writeFile()
{
    std::ofstream output_file("./wordlist.txt");
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(wordlist.begin(), wordlist.end(), output_iterator);

    std::cout << "Done." << std::endl;
}


void generateWordlist()
{
    for(int i = 0; i < keywords.size(); i++)
    {
        for(int j = 0; j < keywords.size(); j++)
        {
            if(j == i && j != keywords.size())
            {
                continue;
            }

            wordlist.push_back(keywords[i]+keywords[j]);
        }
    }

    writeFile();
}


void joinResults(std::vector<std::string> result)
{
    for(int i = 0; i < result.size(); i++)
    {
        keywords.push_back(result[i]);
    }

    generateWordlist();
}

void parseString(std::string n)
{
    std::vector<std::string> result;
    std::stringstream s_stream(n);
    while(s_stream.good())
    {
        std::string substr;
        std::getline(s_stream, substr, ',');
        result.push_back(substr);
    }

    joinResults(result);
}

int main()
{
    std::cout << "Enter the basic info: " << std::endl << std::endl;

    std::cout << "First Name: ";
    std::cin >> n;
    keywords.push_back(n);

    std::cout << "Second Name: ";
    std::cin >> n;
    keywords.push_back(n);

    std::cout << "Favourite Color: ";
    std::cin >> n;
    keywords.push_back(n);

    std::cout << "Year of Birth: ";
    std::cin >> n;
    keywords.push_back(n);

    std::cout << "Pet Name: ";
    std::cin >> n;
    keywords.push_back(n);

    std::cout << std::endl;

    std::cout << "Enter other keywords in a single line separated by a comma (ex.: code,coder,cpp):" << std::endl;
    std::cin >> n;

    parseString(n);

    return 0;
}
