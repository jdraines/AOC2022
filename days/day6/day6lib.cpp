#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include "day6lib.h"

using namespace std;

namespace aoc {

    void printPos(istringstream &stream)
    {
        cout << "pos: " << stream.tellg() << endl;
    }

}

bool containsDup(char arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            if (k == i) {}
            else 
            {
                if (arr[k] == arr[i]) { return true; }
            }
        }
    }
    return false;
}

int getStart(string str, int winSz)
{
    istringstream stream = istringstream(str);
    int sz = winSz;
    int winStart = stream.tellg();
    char window[sz];
    char nxt;

    stream.get(window, sz + 1); 
    winStart++;
    stream.seekg(winStart);

    while (stream.tellg() < str.size() - sz)
    {
        if (!containsDup(window, sz))
        {
            return winStart + (sz - 1);
        }
        else
        {
            stream.get(window, sz + 1);
            winStart++;
            stream.seekg(winStart);
        }
    }
    return str.size();
}
