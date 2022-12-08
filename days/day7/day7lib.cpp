#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "day7lib.h"

using namespace std;


void Dir::addChild(Dir* child) const
{
    children.push_back(child);
}

Dir* Dir::getChild(string childName) const
{
    for (auto c : children)
    {
        if (c->name == childName) { return c; }
    }

    // exit with error message if not found
    cout << "No child directory was found with name '" 
         << childName << "' in directory '" << name << "'" << endl;

    exit(0);
    return 0;
}

File::File(string stat)
{
    size = stoi(stat.substr(0, stat.find(" ")));
    name = stat.substr((stat.find(" ")+1));
}

vector<vector<string>> splitCmds(vector<string> lines)
{
    bool inCmd = false;
    vector<string> cmd;
    vector<vector<string>> cmds;

    for (auto line : lines)
    {
        if (line.find("$") == 0) 
        {
            if (!cmd.empty()) { cmds.push_back(vector(cmd)); }
            cmd.clear();
            cmd.push_back(line);
        }   
        else { cmd.push_back(line); }
    }

    cmds.push_back(cmd);

    for (auto c : cmds) 
    {
        if (c.empty()) { cout << "command is empty." << endl << flush; exit(0); }
    }

    return cmds;
}

Dir* CdHandler::handle(vector<string> cmd, Dir* cwd, Dir* root) const
{
    string dirName = cmd[0].substr(5);
    if (dirName == "/") { return root; } 
    else if (dirName == "..") 
    { 
        if (cwd-> name != "/") { return cwd->parent; } 
        else
        {
            cout << "Cannot perform 'cd ..' from root directory";
            exit(0);
        }
    }
    else { return cwd->getChild(dirName); }
}

Dir* LsHandler::handle(vector<string> cmd, Dir* cwd, Dir* root) const
{
    vector<string> output = vector(cmd.begin() + 1, cmd.end());
    string dirName;

    for (auto o : output)
    {
        if (o.find("dir") == 0)
        {
            dirName = o.substr(4);
            cwd->children.push_back(new Dir(dirName, cwd));
        }
        else
        {
            cwd->files.push_back(File(o));
        }
    }

    return cwd;
}

Handler& getHandler(vector<string> cmd)
{
    if (cmd[0].find("$ cd") == 0) { return *(HANDLERS.at("cd")); }
    else { return *(HANDLERS.at("ls")); }
}

vector<File> getFiles_r(Dir* dir)
{
    vector<File> files = vector(dir->files);
    if(dir->children.size())
    {
        for(auto d : dir->children) 
        {
            for(auto f: getFiles_r(d)) { files.push_back(f); }
        }
    }

    for (auto f : files )
    {
        f.name = dir->name + "/" + f.name;
    }

    return files;
}

vector<Dir*> getDirs_r(Dir* dir)
{
    vector<Dir*> dirs = vector({dir});
    if(dir->children.size())
    {
        for(auto d : dir->children)
        {
            for (auto cd : getDirs_r(d)) { dirs.push_back(cd); }
        }
    }
    return dirs;
}