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
    int numOfNodes;
public:
    SolverAdapter(Searcher<T> *s):searcher(s){};
    string solve(Matrix* prob) override {
        setSearchable(prob);
        // run the search method of the searcher we got
        return searcher->search(prob);
    }
    SolverAdapter* clone() {
        return new SolverAdapter(searcher);
    }

    void setSearchable(Matrix *s){
        searchable = s;
    }
    int getNumOfNodes(){
        return numOfNodes;
    }
};


#endif //EX4_SOLVERADAPTER_H
