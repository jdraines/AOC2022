#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>
#include <stdlib.h>

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

        InputDoc::InputDoc(vector<string> doc)
        {
            doc_ = doc;
            numLines_ = doc.size();
        }
       
        string InputDoc::text() {
            string text_ = "";
            for (auto &s : doc_)
            {
                text_ += (s + "\n");
            }
            return text_.substr(0, text_.size()-1);
        };

        InputDoc InputDoc::subDoc(int start, int stop)
        {
            vector<string> doc;
            doc = vector(doc_.begin() + start, doc_.begin() + stop);
            return InputDoc(doc);
        }

        InputDoc get_input(int argc, char *argv[])
        {
            string fpath = read_cli_arg(argc, argv);
            return InputDoc(fpath);
        };

        string read_cli_arg(int argc, char* argv[])
        {
            string fpath;
            if (argc == 1) { cout << "Must provide an input filename\n"; exit(0); }
            else { fpath = argv[1]; }
            return fpath;
        };

}