//
// Created by noa on 13/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H


#include "Solver.h"
#include "string.h"
#include <string>
#include <algorithm>

using namespace std;
class StringReverser : public Solver<string,string>{
public:
    string solve(string s);
    ~StringReverser();
};


#endif //EX4_STRINGREVERSER_H
