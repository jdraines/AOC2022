#ifndef INPUT_H
#define INPUT_H

#include <fstream>
#include <string>
#include <vector>
#include <cstddef>
#include "input.h"

using namespace std;

namespace aoc {

class InputDoc {
    private:
        size_t numLines_;
        vector<string> doc_;
    public:
        vector<string>& doc();
        const size_t& numLines();
        
        InputDoc(string filepath);
       
        string text();

};

}
#endif // INPUT_H