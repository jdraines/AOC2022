#ifndef DAY2LIB_H
#define DAY2LIB_H

#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <array>
#include <cassert>

using namespace std;

namespace day2
{

    enum ThrowEnum
    {
        rock = 1,
        paper = 2,
        scissors = 3
    };
    enum RoundResult
    {
        win = 6,
        lose = 0,
        tie = 3
    };

    ostream& operator<<(std::ostream& out, const ThrowEnum value);

    class Throw
    {
    public:
        ThrowEnum id;
        map<RoundResult, ThrowEnum> config;
        map<ThrowEnum, RoundResult> versus;
        Throw() = default;
        Throw(ThrowEnum t, map<RoundResult, ThrowEnum> c): 
            id(t), config(c) 
            {
                for (auto [key, value] : c)
                {
                    versus[value] = key;
                }
            }
        int against(Throw opponent) const;
        string toStr() const;
        virtual ~Throw() = default;
    };

    class Rock : public Throw
    {
    public:
        Rock() : Throw(rock, {{tie, rock},
                              {lose, paper},
                              {win, scissors}})
        {
        }
    };

    class Paper : public Throw
    {
    public:
        Paper() : Throw(paper, {{win, rock},
                                {tie, paper},
                                {lose, scissors}}) {}
    };

    class Scissors : public Throw
    {
    public:
        Scissors() : Throw(scissors, {{lose, rock},
                                      {win, paper},
                                      {tie, scissors}}) {}
    };

    Throw getThrow(ThrowEnum t);

    struct Round
    {
        const Throw one;
        const Throw two;
        Round() = default;
        Round(ThrowEnum o, ThrowEnum t);
    };


    namespace part1
    {
        Round parseRoundStr(string &roundStr, map<char, ThrowEnum> throwLookup);
        
        const map<char, ThrowEnum> throwLookup = {
            {'A', rock},
            {'B', paper},
            {'C', scissors},
            {'X', rock},
            {'Y', paper},
            {'Z', scissors}};
    }

    namespace part2
    {
        Round parseRoundStr(string &roundStr, map<char, ThrowEnum> throwLookup);
        
        const map<char, ThrowEnum> throwLookup = {
            {'A', rock},
            {'B', paper},
            {'C', scissors}
        };
    }
}

#endif /* DAY2LIB_H */