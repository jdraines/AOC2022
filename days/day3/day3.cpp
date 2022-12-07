#include <iostream>
#include "../../utils/input.h"
#include "day3lib.h"


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
    vector<vector<char>> itemVec;
    vector<Rucksack> rucks;
    vector<char> misplacedItems;
    int prioritySum = 0;

    for (auto line : input.doc()) { itemVec.push_back(parseItems(line)); }
    for (auto v : itemVec) { rucks.push_back(splitItems(v)); }
    for (auto r : rucks) { misplacedItems.push_back(findItemsToRearrange(r)); }
    for (char c : misplacedItems) { prioritySum += getItemVal(c); }

    cout << "priority sum: " << prioritySum << "\n";
}

void part2(int argc, char* argv[])
{
    aoc::InputDoc input = aoc::get_input(argc, argv);
    vector<vector<char>> itemVec;
    vector<Group> groups;
    vector<char> badges;
    int prioritySum = 0;

    for (auto line : input.doc()) { itemVec.push_back(parseItems(line)); }
    groups = splitIntoGroups(itemVec);
    for (auto g : groups) { badges.push_back(findBadge(g)); }
    for (char c : badges) { prioritySum += getItemVal(c); }

    cout << "priority sum: " << prioritySum << "\n";
}