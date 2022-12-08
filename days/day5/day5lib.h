#ifndef DAY5LIB_H
#define DAY5LIB_H

#include "../../utils/input.h"
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using Stack = vector<char>;

vector<Stack> buildStacks(aoc::InputDoc input);

aoc::InputDoc getStackDiagram(aoc::InputDoc input);

vector<string> getMoves(aoc::InputDoc input);

int getNumStacks(string s);

namespace p1 
{
    void executeMove(string move, vector<Stack>& stacks);
}

namespace p2
{
    void executeMove(string move, vector<Stack>& stacks);
}

#endif /* DAY5LIB_H */