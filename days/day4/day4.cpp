#include <iostream>
#include "../../utils/input.h"
#include "day4lib.h"


void part1(int argc, char* argv[]);
void part2(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    //part1(argc, argv);
    part2(argc, argv);
    return 0;
}

void part1(int argc, char* argv[])
{
    vector<ElfPair> pairs;
    int overlapCount = 0;
    
    aoc::InputDoc input = aoc::get_input(argc, argv);
    for (auto line : input.doc()) { pairs.push_back(ElfPair(line)); }
    for (auto pair : pairs) { overlapCount += pair.fullyOverlapping(); }

    cout << "Number of fully overlapping: " << overlapCount << endl;
}

void part2(int argc, char* argv[])
{
    vector<ElfPair> pairs;
    int overlapCount = 0;
    
    aoc::InputDoc input = aoc::get_input(argc, argv);
    for (auto line : input.doc()) { pairs.push_back(ElfPair(line)); }
    for (auto pair : pairs) { overlapCount += pair.partlyOverlapping(); }

    cout << "Number of partly overlapping: " << overlapCount << endl;
}