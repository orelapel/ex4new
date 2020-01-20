//
// Created by orelapel on 1/19/20.
//

#ifndef EX4_SOLVERADAPTER_H
#define EX4_SOLVERADAPTER_H


#include "Searchable.h"
#include "Point.h"
#include "Searcher.h"

class SolverAdapter {
private:
    Searcher<Point> *searcher;
public:
    SolverAdapter(Searcher<Point> *s);
    string solve(vector<vector<double>> Matrix);
};


#endif //EX4_SOLVERADAPTER_H
