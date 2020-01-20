//
// Created by orelapel on 1/19/20.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include "Point.h"
#include "State.h"
#include "Searchable.h"

class Matrix:public Searchable<Point> {
private:
    vector<vector<double>> matrix;
    vector<vector<State<Point>*>> stateMatrix;
    State<Point> *initial;
    State<Point> *goal;
public:
    Matrix(vector<vector<double>> matrixProblem,State<Point>*intialState,State<Point>*goalState);
    void initialStateMatrix();
    State<Point>* getInitialState();
    bool isGoalState(State<Point>* state);
    vector<State<Point>*> getAllPosibleState(State<Point>* state);
};



#endif //EX4_MATRIX_H
