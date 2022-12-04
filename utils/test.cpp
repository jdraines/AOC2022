#include <iostream>
#include "input.h"

using namespace aoc;

int main(int argc, char** argv) {
    InputDoc input = InputDoc("test.txt");
    cout << input.text();
};