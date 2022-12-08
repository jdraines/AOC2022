#ifndef DAY6LIB_H
#define DAY6LIB_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static const int WINDOW_SIZE = 4;

void printPos(istringstream stream);

int getStart(string str, int winSz=WINDOW_SIZE);

#endif /* DAY6LIB_H */