#ifndef DAY7LIB_H
#define DAY7LIB_H

#include <map>
#include <string>
#include <vector>

using namespace std;

struct File
{
    string name;
    size_t size;
    File() = default;
    File(string n, size_t s): name(n), size(s) {}
    File (string stat);
};

class Dir
{
    public:
        const string name;
        Dir* parent;
        mutable vector<Dir*> children;
        mutable vector<File> files;
        Dir(string n, Dir* p): name(n), parent(p) {}
        void addChild(Dir* child) const;
        Dir* getChild(string childName) const;
};

class Handler
{
    public:
        virtual Dir* handle(vector<string> cmd, Dir* cwd, Dir* root) const = 0;
        virtual ~Handler() {}
};

class CdHandler : public Handler
{   
    public:
        Dir* handle(vector<string> cmd, Dir* cwd, Dir* root) const override;
};

class LsHandler : public Handler
{
    public:
        Dir* handle(vector<string> cmd, Dir* cwd, Dir* root) const override;
};

Handler& getHandler(vector<string> cmd);
vector<vector<string>> splitCmds(vector<string> lines);

vector<File> getFiles_r(Dir* dir);
vector<Dir*> getDirs_r(Dir* dir);

const static map<string, Handler*> HANDLERS = {
    {"cd", new CdHandler()},
    {"ls", new LsHandler()}
};

#endif /* DAY7LIB_H */