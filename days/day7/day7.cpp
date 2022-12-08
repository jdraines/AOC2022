#include <algorithm>
#include <iostream>
#include "../../utils/input.h"
#include "day7lib.h"

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
    const size_t P1_THRESHOLD = 100000;
    Dir root = Dir("/", 0);
    Dir* cwd = &root;
    vector<Dir*> dirs;
    size_t totalSize = 0;
    size_t dirSize = 0;
    aoc::InputDoc input = aoc::get_input(argc, argv);
    vector<vector<string>> cmds = splitCmds(input.doc());

    for (auto cmd : cmds)
    {
        cwd = getHandler(cmd).handle(cmd, cwd, &root);
    }

    dirs = getDirs_r(&root);
    for (auto d : dirs)
    {
        dirSize = 0;
        for(auto f : getFiles_r(d)) {  dirSize += f.size;   }
        if (dirSize < P1_THRESHOLD) { totalSize += dirSize; }
    }
    cout << "Sum of totals: " << totalSize << endl << flush;
}

void part2(int argc, char* argv[])
{
    const size_t TOTAL_SPACE = 70000000;
    const size_t P2_REQ = 30000000;
    size_t needed;
    size_t dirSize = 0;
    vector<Dir*> allDirs;
    vector<size_t> candidates;
    Dir* to_delete;

    Dir root = Dir("/", 0);
    Dir* cwd = &root;
    aoc::InputDoc input = aoc::get_input(argc, argv);
    vector<vector<string>> cmds = splitCmds(input.doc());

    for (auto cmd : cmds)
    {
        cwd = getHandler(cmd).handle(cmd, cwd, &root);
    }

    for(auto f: getFiles_r(&root))
    {
        dirSize += f.size;
    }

    needed = P2_REQ - (TOTAL_SPACE - dirSize);

    allDirs = getDirs_r(&root);
    for (auto d : allDirs)
    {
        dirSize = 0;
        for(auto f : getFiles_r(d)) {  dirSize += f.size;   }
        if (dirSize > needed) { candidates.push_back(dirSize); }
    }

    cout << "Size of dir to delete: " << *min_element(candidates.begin(), candidates.end()) << endl;;

}