#include <string>
#include <utility>
#include "day4lib.h"

using namespace std;


ElfPair::ElfPair(string s): str(s), pair_(extractPair(s))
{
    first = pair_.first;
    second = pair_.second;
}

bool ElfPair::fullyOverlapping()
{
    if ((first.first <= second.first) && (first.second >= second.second))
    { return true; }

    if ((second.first <= first.first) && (second.second >= first.second))
    { return true; }

    return false;
}

bool ElfPair::partlyOverlapping()
{
    if (
        (first.first <= second.first) && (first.second >= second.first)
     || (first.first >= second.first) && (first.first <= second.second)
    )
    { return true; }

    return false;
}

pair<eRange, eRange> extractPair(string s)
{
    pair<string, string> strs = splitOnce(s, ',');
    return pair(
        extractRange(strs.first),
        extractRange(strs.second)
    );
}

eRange extractRange(string s)
{
    pair<string, string> rStr = splitOnce(s, '-');
    return pair(stoi(rStr.first), stoi(rStr.second));
}

pair<string, string> splitOnce(string s, char delim)
{
    string firstStr = s.substr(0, s.find(delim));
    string secondStr = s.substr(s.find(delim) + 1, s.length());
    return pair(firstStr, secondStr);
}