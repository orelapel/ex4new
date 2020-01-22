//
// Created by orelapel on 1/19/20.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H

#include "Point.h"
#include "State.h"
#include "Searchable.h"

class Matrix:public Searchable<Point*> {
private:
    vector<vector<double>> matrix;
    vector<vector<State<Point*>*>> stateMatrix;
    Point *initial;
    Point *goal;
public:
    Matrix(vector<vector<double>> matrixProblem, Point* pInit, Point* pGoal);
    void initialStateMatrix();
    State<Point*>* getInitialState() override;
    bool isGoalState(State<Point*>* state) override;
    vector<State<Point*>*> getAllPosibleState(State<Point*>* state) override;

    State<Point *> *getGoalState() override;
};

#endif //EX4_MATRIX_H
