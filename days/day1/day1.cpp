#include <iostream>
#include <cctype>
#include <algorithm>
#include <numeric>
#include "../../utils/input.h"
#include "day1lib.h"

using namespace std;
using ElfRation = vector<int>;

void part1(int argc, char* argv[]);
void part2(int argc, char* argv[]);

int main(int argc, char* argv[]) 
{
    // part1(argc, argv);
    part2(argc, argv);
    return 0;
}

void part1(int argc, char* argv[])
{
    vector<ElfRation> elves;
    vector<int> elfTotals;
    
    aoc::InputDoc input = aoc::get_input(argc, argv);
    elves = group_elf_rations(input);
    elfTotals = get_elf_totals(elves);
    cout << "max: " << *max_element(elfTotals.begin(), elfTotals.end()) << "\n"; 

}

void part2(int argc, char* argv[])
{
    vector<ElfRation> elves;
    vector<int> elfTotals;
    vector<int> top3;
    
    aoc::InputDoc input = aoc::get_input(argc, argv);

    elves = group_elf_rations(input);
    elfTotals = get_elf_totals(elves);
    top3 = get_top3_elves(elfTotals);

    for (auto e: top3) { cout << e << "\n"; }

    cout << "Top 3 combined: " << reduce(top3.begin(), top3.end()) << "\n";
}