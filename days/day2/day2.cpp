#include <iostream>
#include "../../utils/input.h"
#include "day2lib.h"

using namespace std;

void part1(int argc, char* argv[]);
void part2(int argc, char* argv[]);

int main(int argc, char* argv[]) 
{
    //part1(argc, argv);
    part2(argc, argv);
    return 0;
}

void part1(int argc, char* argv[])
{
    int score = 0;
    vector<day2::Round> rounds;
    aoc::InputDoc input = aoc::get_input(argc, argv);
    

    for (auto i : input.doc())
    {
        rounds.push_back(day2::part1::parseRoundStr(i, day2::part1::throwLookup));
    }

    for (auto r : rounds)
    {
        score += r.one.against(r.two);
    }

    cout << "Total score: " << score << "\n";
}

void part2(int argc, char* argv[])
{
    int score = 0;
    vector<day2::Round> rounds;
    aoc::InputDoc input = aoc::get_input(argc, argv);
    

    for (auto i : input.doc())
    {
        rounds.push_back(day2::part2::parseRoundStr(i, day2::part2::throwLookup));
    }

    for (auto r : rounds)
    {
        // cout << "UNO:\n" << r.one.toStr() << endl;
        // cout << "DOS:\n" << r.two.toStr() << endl;
        score += r.one.against(r.two);
        // cout << "SCORE: " << r.one.against(r.two) << "\n-----\n\n";
    }

    cout << "Total score: " << score << "\n";
}