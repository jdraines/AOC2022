#ifndef DAY1LIB_H
#define DAY1LIB_H

#include <vector>
#include "../../utils/input.h"

using namespace std;
using ElfRation = vector<int>;

vector<ElfRation> group_elf_rations(aoc::InputDoc input);

vector<int> get_elf_totals(vector<ElfRation> elves);

vector<int> get_top3_elves(vector<int>);

#endif /* DAY1LIB_H */