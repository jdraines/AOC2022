#ifndef DAY3LIB_H
#define DAY3LIB_H

#include <vector>
#include <utility>
#include <tuple>
#include <stdexcept>

using namespace std;

typedef pair<vector<char>, vector<char>> Rucksack;

struct Group 
{
    vector<char> first;
    vector<char> second;
    vector<char> third;

    Group() = default;

    vector<char>& operator[](size_t i) {
        if (i == 0) { return first; }
        else if (i == 1) { return second; }
        else if (i == 2) {return third; }
        else { out_of_range("index out of range."); }
    }
};

int getItemVal(char item);

bool itemInCompartment(char item, vector<char> cptmt);

char findItemsToRearrange(Rucksack ruck);

pair<vector<char>, vector<char>> splitItems(vector<char> items);

vector<char> parseItems(string itemStr);

vector<Group> splitIntoGroups(vector<vector<char>> itemVec);

char findBadge(Group g);

#endif /* DAY3LIB_H */