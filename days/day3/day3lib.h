#ifndef DAY3LIB_H
#define DAY3LIB_H

#include <vector>
#include <utility>

using namespace std;

typedef pair<vector<char>, vector<char>> Rucksack;

int getItemVal(char item);

bool itemInCompartment(char item, vector<char> cptmt);

char findItemsToRearrange(Rucksack ruck);

pair<vector<char>, vector<char>> splitItems(vector<char> items);

vector<char> parseItems(string itemStr);

#endif /* DAY3LIB_H */