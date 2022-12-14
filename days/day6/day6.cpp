#include <iostream>
#include "../../utils/input.h"
#include "day6lib.h"


void part1(int argc, char* argv[]);
void part2(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    part1(argc, argv);
    part2(argc, argv);
    return 0;
}

void part1(int argc, char* argv[])
{
    aoc::InputDoc input = aoc::get_input(argc, argv);
    cout << "start packet: " << getStart(input.text(), 4) << endl;
}

void part2(int argc, char* argv[])
{
    aoc::InputDoc input = aoc::get_input(argc, argv);
    cout << "start message: " << getStart(input.text(), 14) << endl;
}