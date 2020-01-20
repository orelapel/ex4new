//
// Created by orelapel on 1/19/20.
//

#ifndef EX4_SOLVERADAPTER_H
#define EX4_SOLVERADAPTER_H


#include "Searchable.h"
#include "Point.h"
#include "Searcher.h"
#include "Solver.h"

class SolverAdapter:Solver<vector<vector<double>>*, string> {
private:
    Searcher<Point> *searcher;
    Point *initialP, *goalP;
public:
    SolverAdapter(Searcher<Point> *s);
    string solve(vector<vector<double>>* Matrix);
};


#endif //EX4_SOLVERADAPTER_H
