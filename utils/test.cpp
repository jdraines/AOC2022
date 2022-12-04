#include <iostream>
#include "input.h"

void main(int argc, char* argv) {
    InputDoc input = InputDoc("test.txt");
    cout << input.text();
};