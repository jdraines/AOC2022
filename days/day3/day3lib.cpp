#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include "day3lib.h"

using namespace std;


int getItemVal(char item)
{
    if ((int)item >= 97) { return item - 96;  }
    else {                 return item - 38;  }
}

bool itemInCompartment(char item, vector<char> cptmt)
{
    return find(cptmt.begin(), cptmt.end(), item) != cptmt.end();
}

char findItemsToRearrange(Rucksack ruck)
{
    char c_ = '\0';
    for (auto c : ruck.first)
    {
        if (itemInCompartment(c, ruck.second)) { return c; }
    }
    for (auto c : ruck.second)
    {
        if (itemInCompartment(c, ruck.first)) { return c; }
    }
    return c_;
}

pair<vector<char>, vector<char>> splitItems(vector<char> items)
{
    // index should be 0 or 1

    size_t size = items.size();
    size_t half = size / 2;
    
    return pair(
        vector<char>(items.begin(), (items.begin() + half)), 
        vector<char>((items.begin() + half), items.end())
    ); 
}

vector<char> parseItems(string itemStr)
{
    vector<char> cVec;
    for (char c : itemStr) { cVec.push_back(c); }
    return cVec;
}