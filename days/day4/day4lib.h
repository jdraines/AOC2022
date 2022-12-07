#ifndef DAY4LIB_H
#define DAY4LIB_H

#include <string>
#include <utility>

using namespace std;
using eRange = pair<int,int>;


class ElfPair
{
    private:
        string str;
        pair<eRange, eRange> pair_;
    
    public:
        eRange first;
        eRange second;
        ElfPair() = default;
        ElfPair(string s);
        bool fullyOverlapping();
        bool partlyOverlapping();
};

pair<eRange, eRange> extractPair(string s);

eRange extractRange(string s);

pair<string, string> splitOnce(string s, char delim);

#endif /* DAY4LIB_H */