#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include "../../utils/input.h"

using namespace std;
using ElfRation = vector<int>;


vector<ElfRation> group_elf_rations(aoc::InputDoc input)
{
    vector<ElfRation> elves;
    ElfRation ration;
    
    // group rations by elf
    for (auto line : input.doc())
    {   
        auto isOnlySpace = [](char c) { return isspace(static_cast<unsigned char>(c)); };
        bool onSpace = true;

        if (all_of(line.begin(), line.end(), isOnlySpace) || line.empty())
        { 
            switch(ration.empty())
            {
                case true:
                    break;
                case false:
                    elves.push_back(ration);
            }
            ration = ElfRation();
            onSpace = true;
        }
        else { ration.push_back(stoi(line)); onSpace = false;}
    }
    elves.push_back(ration); // push the final ration into place
    return elves;
}

vector<int> get_elf_totals(vector<ElfRation> elves)
{
    vector<int> elfTotals;
    for (auto elf : elves)
    {
        elfTotals.push_back(reduce(elf.begin(), elf.end()));
    }
    return elfTotals;
}

vector<int> get_top3_elves(vector<int> elves)
{
    sort(elves.begin(), elves.end());
    return vector<int>((elves.end() - 3), elves.end());
}