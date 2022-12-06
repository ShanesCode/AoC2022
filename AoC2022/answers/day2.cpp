#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum Hand 
{
	Rock,
	Paper,
	Scissors,
};

enum Outcome 
{
	Loss,
	Draw,
	Victory,
};

const std::string FILENAME = "input_day2.txt";
int GetPointsFromOutcome(const Outcome outcome);
Hand GetHandFromChar(const char c);
Outcome GetResultFromChar(const char c);
Hand GetHandToPlayToAchieveResult(const Hand opponentsHand, const Outcome result);
Outcome GetOutComeFromMatch(const std::string string);

int main()
{
	std::ifstream inputFile(FILENAME);
	int totalScore = 0;

	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			if (line.size() != 0)
			{
				// Part 1
				/*Outcome outcome = GetOutComeFromMatch(line);
				int resultScore = GetPointsFromOutcome(outcome);
				int handScore = GetHandFromChar(line[2]) + 1;
				int score = resultScore + handScore;*/

				//Part 2
				Outcome outcome = GetResultFromChar(line[2]);
				Hand opponentsHand = GetHandFromChar(line[0]);
				Hand handToPlay = GetHandToPlayToAchieveResult(opponentsHand, outcome);
				int resultScore = GetPointsFromOutcome(outcome);
				int handScore = handToPlay + 1;
				int score = resultScore + handScore;
				totalScore += score;
			}
		}

		inputFile.close();
	}

	std::cout << totalScore << std::endl;
}


int GetPointsFromOutcome(const Outcome outcome)
{
	switch (outcome)
	{
		case Loss: 
		{
			return 0;
		}
		case Draw:
		{
			return 3;
		}
		case Victory:
		{
			return 6;
		}
	}
}

Hand GetHandFromChar(const char c)
{
	if (/*c == 'X' || */c == 'A')
	{
		return Rock;
	}
	if (/*c == 'Y' || */c == 'B')
	{
		return Paper;
	}
	if (/*c == 'Z' || */c == 'C')
	{
		return Scissors;
	}
}

Outcome GetResultFromChar(const char c)
{
	if (c == 'X')
	{
		return Loss;
	}
	if (c == 'Y')
	{
		return Draw;
	}
	if (c == 'Z')
	{
		return Victory;
	}
}

Hand GetHandToPlayToAchieveResult(const Hand opponentsHand, const Outcome result)
{
	Hand hand = Rock;
	int handIndex = 0;
	const int numberOfHands = 3;
	switch (result)
	{
		case Loss:
		{
			handIndex = (opponentsHand - 1) % numberOfHands;
			break;
		}
		case Draw:
		{
			handIndex = opponentsHand;
			break;
		}
		case Victory:
		{
			handIndex = (opponentsHand + 1) % numberOfHands;
			break;
		}
	}

	if (handIndex < 0)
	{
		handIndex = numberOfHands + handIndex;
	}

	return hand = static_cast<Hand>(handIndex);
}

Outcome GetOutComeFromMatch(const std::string string)
{
	Hand opponentsHand = GetHandFromChar((string[0]));
	Hand ourHand = GetHandFromChar((string[2]));

	if (opponentsHand == ourHand)
	{
		return Draw;
	}

	if (opponentsHand > ourHand)
	{
		if (opponentsHand - ourHand == 1)
		{
			return Loss;
		}
		else
		{
			return Victory;
		}
	}
	else
	{
		if (ourHand - opponentsHand == 1)
		{
			return Victory;
		}
		else
		{
			return Loss;
		}
	}
}