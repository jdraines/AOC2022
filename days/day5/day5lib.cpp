#include "../../utils/input.h"
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include "day5lib.h"
#include <array>

vector<Stack> buildStacks(aoc::InputDoc input)
{
    vector<Stack> stacks;
    Stack stack_;
    string line;
    char c;
    size_t lbrace_interval = 4;
    
    aoc::InputDoc diagram = getStackDiagram(input);
    int numStacks = getNumStacks(diagram.doc()[diagram.numLines() - 1]);

    for (int i = 0; i < numStacks; i++)
    {
        stack_.clear();
        for (int j = diagram.numLines() - 2; j >= 0; j--)
        {
            line = diagram.doc()[j];
            c = line[(i * lbrace_interval) + 1];
            if (!isspace(c)) {stack_.push_back(c);}
        }
        stacks.push_back(stack_);
    }
    return stacks;
}

aoc::InputDoc getStackDiagram(aoc::InputDoc input)
{
    int start = 0;
    int stop = 0;

    for (auto line : input.doc())
    {
        if (line.rfind(" 1", 0) == 0) { stop++; break; }
        else { stop++; }
    }
    return input.subDoc(start, stop);
}

vector<string> getMoves(aoc::InputDoc input)
{
    int start = 0;
    int stop = 0;

    for (auto line : input.doc())
    {
        if (line.rfind(" 1", 0) == 0) { start += 2; break; }
        else { start++; }
    }

    return input.subDoc(start, input.numLines()).doc();
}

int getNumStacks(string s)
{
    vector<int> ints;
    // works for 1-9 stacks
    for (char c : s) { if (!isspace(c)) { ints.push_back(atoi(&c)); } }
    return *max_element(ints.begin(), ints.end());
}

array<int,3> parseMoveStr(string move)
{
    int spaces[2];
    int numMoves;
    int srcIdx;
    int destIdx;

    string move_ = string(move);

    move_.erase(move_.find("move "), 5);
    move_.erase(move_.find("from "), 5);
    move_.erase(move_.find("to "), 3);

    spaces[0] = move_.find(" ");
    spaces[1] = move_.substr(spaces[0] + 1).find(" ") + (spaces[0] + 1);
    numMoves = stoi(move_.substr(0, spaces[0]));
    srcIdx = stoi(move_.substr(spaces[0] + 1, spaces[1])) - 1;
    destIdx = stoi(move_.substr(spaces[1] + 1)) - 1;

    return array<int,3> {numMoves, srcIdx, destIdx};
}

namespace p1 {

    void executeMove(string move, vector<Stack>& stacks)
    {
        Stack srcStack;
        Stack destStack;
        char pallet;

        array<int,3> elements = parseMoveStr(move);

        int numMoves = elements[0];
        size_t srcIdx = elements[1];
        size_t destIdx = elements[2];


        for (int i = 0; i < numMoves; i++)
        {
            srcStack = stacks.at(srcIdx);
            destStack = stacks.at(destIdx);
            pallet = srcStack.back();
            srcStack.pop_back();
            destStack.push_back(pallet);
            stacks.at(srcIdx).assign(srcStack.begin(), srcStack.end());
            stacks.at(destIdx).assign(destStack.begin(), destStack.end());
        }
    }

}

namespace p2 {

    void executeMove(string move, vector<Stack>& stacks)
    {
        Stack srcStack;
        Stack destStack;
        char pallet;
        Stack moveStack;

        array<int,3> elements = parseMoveStr(move);

        int numMoves = elements[0];
        size_t srcIdx = elements[1];
        size_t destIdx = elements[2];

        srcStack = stacks.at(srcIdx);
        destStack = stacks.at(destIdx);
        moveStack = vector(srcStack.end()-numMoves, srcStack.end());
        for (auto i : moveStack) {destStack.push_back(i); srcStack.pop_back();}
        
        stacks.at(srcIdx).assign(srcStack.begin(), srcStack.end());
        stacks.at(destIdx).assign(destStack.begin(), destStack.end());
    }

}