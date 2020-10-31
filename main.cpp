#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>

//vector that will hold the complete wordlist
std::vector<std::string> wordlist;

//vector to store keywords
std::vector<std::string> keywords;

std::string n;

bool changeChars = false;
bool addSymbols = false;

void writeFile()
{
    std::ofstream output_file("./wordlist.txt");
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(wordlist.begin(), wordlist.end(), output_iterator);

    std::cout << "\nDone." << std::endl;
}


void generateWordlist()
{
    for(std::size_t i = 0; i < keywords.size(); i++)
    {
        for(std::size_t j = 0; j < keywords.size(); j++)
        {
            if(j == i && j != keywords.size())
            {
                continue;
            }

            if(addSymbols)
            {
                std::string symbols_arr[] = {"!","@","#","£","$","§","%","&"};

                for(std::size_t k = 0; k < 8; k++)
                {
                    std::string temp = keywords[j] + symbols_arr[k];
                    wordlist.push_back(keywords[i] + temp);
                }
            }

            wordlist.push_back(keywords[i] + keywords[j]);
        }
    }

    writeFile();
}


void joinResults(std::vector<std::string> result)
{
    for(std::size_t i = 0; i < result.size(); i++)
    {
        keywords.push_back(result[i]);
    }

    if(changeChars == true)
    {
        std::size_t keywords_size = keywords.size();
        for(std::size_t i = 0; i < keywords_size; i++)
        {
            std::string temp = keywords[i];
            for(std::size_t j = 0; j < temp.length(); j++)
            {
                if(temp[j] == 'A' || temp[j] == 'a')
                {
                    temp[j] = '4';
                }
                else if(temp[j] == 'E' || temp[j] == 'e')
                {
                    temp[j] = '3';
                }
                else if(temp[j] == 'O' || temp[j] == 'o')
                {
                    temp[j] = '0';
                }
                else if(temp[j] == 'I' || temp[j] == 'i')
                {
                    temp[j] = '1';
                }
                else if(temp[j] == 'S' || temp[j] == 's')
                {
                    temp[j] = '5';
                }
            }
            keywords.push_back(temp);
        }
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
    getline(std::cin, n);
    keywords.push_back(n);

    std::cout << "Second Name: ";
    getline(std::cin, n);
    keywords.push_back(n);

    std::cout << "Favourite Color: ";
    getline(std::cin, n);
    keywords.push_back(n);

    std::cout << "Year of Birth: ";
    getline(std::cin, n);
    keywords.push_back(n);

    std::cout << "Pet Name: ";
    getline(std::cin, n);
    keywords.push_back(n);

    std::cout << std::endl;

    std::cout << "Enter other keywords in a single line separated by a comma (ex.: code,coder,cpp) | Or leave empty:" << std::endl << std::endl;
    getline(std::cin, n);

    std::cout << "\nDo you want to change letters by numbers? This will double the size of the wordlist. (y/n)" << std::endl;
    char answer_num;
    std::cin >> answer_num;

    if (answer_num == 'y' || answer_num == 'Y')
    {
        changeChars = true;
    }

    std::cout << "\nDo you want to add symbols to the end of the words? (y/n)" << std::endl;
    char answer_sym;
    std::cin >> answer_sym;

    if (answer_sym == 'y' || answer_sym == 'Y')
    {
        addSymbols = true;
    }

    parseString(n);

    return 0;
}
