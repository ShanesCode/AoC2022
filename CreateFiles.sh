#!/bin/bash

if [ ! -d "AoC2022/code" ] 
then
    mkdir AoC2022/code
fi

if [ ! -d "AoC2022/input" ] 
then
    mkdir AoC2022/input
fi

for((i=0;i<=25;++i))
    do
        if [ ! -f AoC2022/code/day${i}.cpp ]
        then
            # create template c++ file
            echo "#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string FILENAME = \"input/input_day${i}.txt\";
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
}" > AoC2022/code/day${i}.cpp;
        fi
        if [ ! -f AoC2022/input/day${i}.cpp ]
        then
            echo ""  > AoC2022/input/input_day${i}.txt
        fi
    done