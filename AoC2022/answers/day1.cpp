#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string FILENAME = "input_day1.txt";

int GetHighestCalories(std::string file);
std::vector<int> GetTopHighestCalories(int rankedElves, std::string file);

int main()
{
    // std::cout << GetHighestCalories(FILENAME) << std::endl;
    std::vector<int> topHighestCalories = GetTopHighestCalories(3, FILENAME);
    int sum = 0;
    for (int i = 0; i < topHighestCalories.size(); i++)
    {
        sum += topHighestCalories[i];
    }
    std::cout << sum << std::endl;
}

int GetHighestCalories(std::string file)
{
    // Part 1
    std::ifstream inputFile(FILENAME);

    int elfTotalCalories = 0;
    int highestTotalCalories = 0;
    int lineCals = 0;

    if (inputFile.is_open())
    {
        std::string line;
        while (std::getline(inputFile, line))
        {
            if (line.size() != 0)
            {
                lineCals = std::stoi(line);
                elfTotalCalories += lineCals;
            }
            else
            {
                if (elfTotalCalories > highestTotalCalories)
                {
                    highestTotalCalories = elfTotalCalories;
                }

                elfTotalCalories = 0;
            }
        }
        inputFile.close();
    }

    return highestTotalCalories;
}

std::vector<int> GetTopHighestCalories(int rankedElves, std::string file)
{
    // Part 2
    std::ifstream inputFile(FILENAME);

    std::vector<int> topHighestCalories;

    int elfTotalCalories = 0;
    int lineCals = 0;

    if (inputFile.is_open())
    {
        std::string line;
        while (std::getline(inputFile, line))
        {
            if (line.size() != 0)
            {
                lineCals = std::stoi(line);
                elfTotalCalories += lineCals;
            }
            else
            {
                int rank = -1;
                for (int i = rankedElves - 1; i >= 0; i--)
                {
                    if (topHighestCalories.size() <= i)
                    {
                        rank = i;
                        continue;
                    }

                    if (elfTotalCalories > topHighestCalories[i])
                    {
                        rank = i;
                    }
                    else
                    {
                        break;
                    }
                }

                    
                if (rank >= 0 && rank < rankedElves)
                {
                    auto pos = topHighestCalories.begin() + rank;
                    topHighestCalories.insert(pos, elfTotalCalories);

                    if (topHighestCalories.size() > rankedElves)
                    {
                        topHighestCalories.pop_back();
                    }
                }

                elfTotalCalories = 0;
            }
        }
        inputFile.close();
    }

    return topHighestCalories;
}