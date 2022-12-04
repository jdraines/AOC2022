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
        vector<string>& doc();
        const size_t& const numLines();
        
        InputDoc(string filepath);
       
        string text();

};