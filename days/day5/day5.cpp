#include <iostream>
#include "../../utils/input.h"
#include "day5lib.h"


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
    aoc::InputDoc input = aoc::get_input(argc, argv);
    vector<Stack> stacks = buildStacks(input);
    vector<string> moves = getMoves(input);
    for (auto move : moves) { p1::executeMove(move, stacks); }
    for (auto stack : stacks) { cout << stack.back(); }
    cout << endl;
}

void part2(int argc, char* argv[])
{
    aoc::InputDoc input = aoc::get_input(argc, argv);
    vector<Stack> stacks = buildStacks(input);
    vector<string> moves = getMoves(input);
    for (auto move : moves) { p2::executeMove(move, stacks); }
    for (auto stack : stacks) { cout << stack.back(); }
    cout << endl;
}