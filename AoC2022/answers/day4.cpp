#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string FILENAME = "input_day4.txt";

int main()
{
	std::ifstream inputFile(FILENAME);
	//int numberOfContainments = 0;
	int numberOfOverlaps = 0;
	int lineLength = 0;

	std::string firstElfStartStr = "";
	std::string firstElfEndStr = "";
	std::string secondElfStartStr = "";
	std::string secondElfEndStr = "";

	int firstElfStart = 0;
	int firstElfEnd = 0;
	int secondElfStart = 0;
	int secondElfEnd = 0;

	const char RANGE = '-';
	const char DIVIDER = ',';

	int count = 0;
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			if (line.size() != 0)
			{
				lineLength = line.length();
				count = 0;
				while (line[count] != RANGE)
				{
					firstElfStartStr += line[count];
					++count;
				}
				++count;

				while (line[count] != DIVIDER)
				{
					firstElfEndStr += line[count];
					++count;
				}
				++count;

				while (line[count] != RANGE)
				{
					secondElfStartStr += line[count];
					++count;
				}
				++count;

				while (count != lineLength)
				{
					secondElfEndStr += line[count];
					++count;
				}

				firstElfStart = std::stoi(firstElfStartStr);
				firstElfEnd = std::stoi(firstElfEndStr);
				secondElfStart = std::stoi(secondElfStartStr);
				secondElfEnd = std::stoi(secondElfEndStr);

				// Part 1
				/*if (firstElfStart <= secondElfStart && firstElfEnd >= secondElfEnd)
				{
					numberOfContainments++;
				}
				else if (secondElfStart <= firstElfStart && secondElfEnd >= firstElfEnd)
				{
					numberOfContainments++;
				}*/

				if (firstElfStart <= secondElfStart && firstElfEnd >= secondElfStart)
				{
					numberOfOverlaps++;
				}
				else if (secondElfStart <= firstElfStart && secondElfEnd >= firstElfStart)
				{
					numberOfOverlaps++;
				}
				else if (firstElfEnd >= secondElfStart && firstElfEnd <= secondElfEnd)
				{
					numberOfOverlaps++;
				}
				else if (secondElfEnd >= firstElfStart && secondElfEnd <= firstElfEnd)
				{
					numberOfOverlaps++;
				}

				firstElfStartStr.clear();
				firstElfEndStr.clear();
				secondElfStartStr.clear();
				secondElfEndStr.clear();
			}
		}

		inputFile.close();
	}

	std::cout << numberOfOverlaps << std::endl;
}