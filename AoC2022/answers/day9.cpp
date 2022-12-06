#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string FILENAME = "input/input_day9.txt";
int main(){
    std::ifstream inputFile(FILENAME);

    if (inputFile.is_open())
    {
        std::string line;
        while (std::getline(inputFile, line))
        {
            if (line.size() != 0)
            {

            }
        }

        inputFile.close();
    }

    return 0;
}
