//
// Created by orelapel on 1/19/20.
//

#ifndef EX4_SOLVERADAPTER_H
#define EX4_SOLVERADAPTER_H


//#include "Searchable.h"
//#include "Point.h"
#include "Searcher.h"
#include "Solver.h"

template <class T>
class SolverAdapter:public Solver<Matrix*, string> {
    Searcher<T> *searcher;
    Matrix *searchable;
//    Point *initialP, *goalP;
public:
    SolverAdapter(Searcher<T> *s):searcher(s){};
    string solve(Matrix* prob) override {
        setSearchable(prob);
        return searcher->search(prob);
    }
    void setSearchable(Matrix *s){
        searchable = s;
    }
};


#endif //EX4_SOLVERADAPTER_H
