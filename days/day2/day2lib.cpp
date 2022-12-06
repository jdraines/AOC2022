#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <array>
#include <iostream>
#include <stdexcept>
#include "day2lib.h"

using namespace std;

namespace day2
{

    ostream &operator<<(std::ostream &out, const ThrowEnum value)
    {
        static std::map<ThrowEnum, std::string> strings;
        if (strings.size() == 0)
        {
#ifndef INSERT_ELEMENT_TE
#define INSERT_ELEMENT_TE(p) strings[p] = #p
            INSERT_ELEMENT_TE(rock);
            INSERT_ELEMENT_TE(paper);
            INSERT_ELEMENT_TE(scissors);
#undef INSERT_ELEMENT
#endif
        }
        return out << strings[value];
    }
    int Throw::against(Throw opponent) const
    {
        RoundResult res = opponent.versus.find(id)->second;
        return res + opponent.id;
    }

    string Throw::toStr() const
    {
        stringstream ss;
        ss << "id: " << id << "\n";
        ss << "config:\n";
        for (auto [key, value] : versus)
        {
            ss << "key: " << key << ", value: " << value << "\n";
        }
        return ss.str();
    }

    Throw getThrow(ThrowEnum t)
    {
        if (t == rock)
        {
            return Rock();
        }
        else if (t == paper)
        {
            return Paper();
        }
        else
        {
            assert((t == scissors));
            return Scissors();
        }
    }

    Round::Round(ThrowEnum o, ThrowEnum t) : one(getThrow(o)), two(getThrow(t)) {}

    namespace part1
    {

        Round parseRoundStr(string &roundStr, map<char, ThrowEnum> throwLookup)
        {

            ThrowEnum uno = throwLookup.find(roundStr[0])->second;
            ThrowEnum dos = throwLookup.find(roundStr[2])->second;

            return Round(
                uno,
                dos);
        }
    }

    namespace part2
    {

        Round parseRoundStr(string &roundStr, map<char, ThrowEnum> throwLookup)
        {
            ThrowEnum uno = throwLookup.find(roundStr[0])->second;
            
            Throw unoThrow;
            if (uno == rock) {unoThrow = Rock();}
            else if (uno == paper) {unoThrow = Paper();}
            else if (uno == scissors) {unoThrow = Scissors();}
            
            RoundResult oppRes;
            if (roundStr[2] == 'X') {oppRes = win;}
            if (roundStr[2] == 'Y') {oppRes = tie;}
            if (roundStr[2] == 'Z') {oppRes = lose;}
            
            ThrowEnum dos = unoThrow.config.find(oppRes)->second;

            return Round(
                uno,
                dos);
        }

    }

}