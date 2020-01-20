//
// Created by orelapel on 1/19/20.
//

#include "SolverAdapter.h"
#include "Matrix.h"

SolverAdapter::SolverAdapter(Searcher<Point> *s){
    searcher =s;
}

string SolverAdapter::solve(vector<vector<double>>* matrix) {
    // TODO check if initial and goal are always the start and end of the matrix
    int i = matrix->size(), j = matrix->front().size();
    Searchable<Point> *matrixSearch= new Matrix(matrix, new Point(0,0), new Point(i,j));
    searcher->search(matrixSearch);
}