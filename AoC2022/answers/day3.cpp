#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string FILENAME = "input_day3.txt";

int GetPriorityScoreOfItem(const char c);

int main()
{
	std::ifstream inputFile(FILENAME);
	// char commonItem = '/0';
	int totalScore = 0;
	std::map<const char, std::vector<int>> itemToElvesMap;
	
	if (inputFile.is_open())
	{
		std::string line;
		int elfIndex = 0;
		while (std::getline(inputFile, line))
		{
			if (elfIndex % 3 == 0)
			{
				itemToElvesMap.clear();
			}

			if (line.size() != 0)
			{
				// Part 1
				//const int rucksacksCombinedCapacity = line.length();
				//const int singleRucksackCapacity = rucksacksCombinedCapacity / 2;
				//std::map<const char, int> charMap;

				//for (int i = 0; i < singleRucksackCapacity; ++i)
				//{
				//	if (!charMap.count(line[i]))
				//	{
				//		charMap[line[i]] = 1;
				//	}
				//	charMap[line[i]]++;
				//}

				//for (int j = singleRucksackCapacity; j < rucksacksCombinedCapacity; ++j)
				//{
				//	if (charMap.count(line[j]))
				//	{
				//		commonItem = line[j];
				//		break;
				//	}
				//}

				const int rucksackCapacity = line.length();
				int priorityScore = 0;

				for (int i = 0; i < rucksackCapacity; ++i)
				{
					std::vector<int> elves;
					const char item = line[i];
					if (!itemToElvesMap.count(item))
					{
						itemToElvesMap[item] = elves;
					}
					else
					{
						elves = itemToElvesMap[item];
					}

					bool elfAlreadyMapped = false;
					for (int e = 0; e < elves.size(); ++e)
					{
						if (elves[e] == elfIndex)
						{
							elfAlreadyMapped = true;
							break;
						}
					}

					if (elfAlreadyMapped)
					{
						continue;
					}

					itemToElvesMap[item].push_back(elfIndex);
					
					if (itemToElvesMap[item].size() == 3)
					{
						priorityScore = GetPriorityScoreOfItem(item);
						break;
					}
				}
				totalScore += priorityScore;
			}

			elfIndex++;
		}

		inputFile.close();
	}

	std::cout << totalScore << std::endl;
}

int GetPriorityScoreOfItem(const char c)
{
	int score = c;
	const int lowestUpperCaseScore = 27;
	const int lowestLowerCaseScore = 1;
	const int lowestUpperAsciiIntValue = 65;
	const int lowestLowerAsciiIntValue = 97;
	const int upperCaseDifference = lowestUpperAsciiIntValue - lowestUpperCaseScore;
	const int lowerCaseDifference = lowestLowerAsciiIntValue - lowestLowerCaseScore;

	if (score < 96)
	{
		score -= upperCaseDifference;
	}
	else
	{
		score -= lowerCaseDifference;
	}

	return score;
}

// 3 elves per group
// Elves are grouped by a single common item, which has a score
// Elves can appear in multiple groups
// Need to find common items between elves
// Once 3 are found, that item is no longer checked for

// First elf, add each of its items to a map (but only once)
// Second elf, add new items to the map. We should know which elf's item it is.
// So the map should be a map of items to elves.

// Once an item has 3 elves, we don't need to check it any more.
// Add the items score to the total score.