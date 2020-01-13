//
// Created by noa on 13/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

template <class Problem, class Solution>
class Solver {
    virtual Solution solve(Problem p);
};

#endif //EX4_SOLVER_H
