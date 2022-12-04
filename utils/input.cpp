#include <fstream>
#include <string>
#include <vector>
#include <cstddef>

using namespace std;

class InputDoc {
    private:
        size_t numLines_;
        vector<string> doc_;
    public:
        vector<string>& doc() { return doc_; };
        const size_t& const numLines() { return numLines_; };
        
        InputDoc(string filepath) {
            ifstream file(filepath);
            string line;
            while (getline(file, line))
            {
                doc_.push_back(line);
            }
            doc_.shrink_to_fit();
            numLines_ = doc_.size();
        };
       
        string text() {
            string text_ = "";
            for (auto &s : doc_)
            {
                text_ += s;
            }
            return text_;
        };

};