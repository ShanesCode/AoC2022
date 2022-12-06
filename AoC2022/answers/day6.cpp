#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string FILENAME = "input/input_day6.txt";
bool DuplicateInString(const std::string& str);

int main(){
    std::ifstream inputFile(FILENAME);

    if (inputFile.is_open())
    {
        std::string input;
        std::getline(inputFile, input);

        int i = 13;
        std::string subString = "";
        
        while (i <= input.size())
        {
            subString.clear();
            subString = input.substr(i - 13, 14);
            if (!DuplicateInString(subString))
            {
                std::cout << i + 1 << std::endl;
                break;
            }

            ++i;
        }

        inputFile.close();
    }

    return 0;
}

bool DuplicateInString(const std::string& str)
{
    size_t length = str.length();
    if (length == 2)
    {
        return str[0] == str[1];
    }

    for (int i = 1; i < length; ++i)
    {
        if (str[0] == str[i])
        {
            return true;
        }
    }

    return DuplicateInString(str.substr(1, length));
}