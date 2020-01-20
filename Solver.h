//
// Created by noa on 13/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
#include "string"
using namespace std;
template <class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem p)=0;
    //virtual string solve(string s)=0;
};

#endif //EX4_SOLVER_H
