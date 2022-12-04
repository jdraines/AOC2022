#include <fstream>
#include <string>
#include <vector>
#include <cstddef>

#include "input.h"

using namespace std;

namespace aoc 
{

        vector<string>& InputDoc::doc() { return doc_; };
        const size_t& InputDoc::numLines() { return numLines_; };
        
        InputDoc::InputDoc(string filepath) {
            ifstream file(filepath);
            string line;
            while (getline(file, line))
            {
                doc_.push_back(line);
            }
            doc_.shrink_to_fit();
            numLines_ = doc_.size();
        };
       
        string InputDoc::text() {
            string text_ = "";
            for (auto &s : doc_)
            {
                text_ += s;
            }
            return text_;
        };

}