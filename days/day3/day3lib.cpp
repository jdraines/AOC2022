#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include "day3lib.h"
#include <array>
#include <algorithm>

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

vector<Group> splitIntoGroups(vector<vector<char>> itemVec)
{
    vector<Group> grouped;
    Group g;
    int n = 0;

    for (auto v : itemVec)
    {
        g[n] = v;
        if (n == 2) {grouped.push_back(g); n = 0;}
        else { n++; } 
    }

    return grouped;
}

char findBadge(Group g)
{
    char c_ = '\0';
    for (auto c : g[0])
    {
        if (   itemInCompartment(c, g[1])
            && itemInCompartment(c, g[2]))
        { return c; }
    }
    return c_;
}