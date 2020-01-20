//
// Created by orelapel on 1/19/20.
//

#include "SolverAdapter.h"
#include "Matrix.h"

SolverAdapter::SolverAdapter(Searcher<Point> *s){
    searcher =s;
}

string SolverAdapter::solve(vector<vector<double>> matrix) {
    State<Point> *initial, *goal;
    Searchable<Point> *matrixSearch= new Matrix(matrix, initial, goal);
    //searcher->Search()
}