//
// Created by orelapel on 1/19/20.
//

#include "Matrix.h"

Matrix::Matrix(vector<vector<double>> matrixProblem, Point* pInit, Point* pGoal) {
    matrix = matrixProblem;
    initial = pInit;
    goal = pGoal;
    initialStateMatrix();
}

void Matrix::initialStateMatrix() {
    int i=0,j;
    for (std::vector<vector<double>>::iterator it = matrix.begin(); it != matrix.end(); ++it) {
        j=0;
        vector<State<Point*>*> stateVector;
        for (std::vector<double>::iterator itIn = (*it).begin(); itIn != (*it).end(); ++itIn) {
            stateVector.push_back(new State<Point*>(new Point(i,j), NULL, (*itIn)));
            j++;
        }
        stateMatrix.push_back(stateVector);
        i++;
    }
}

State<Point*>* Matrix::getInitialState() {
    int i = initial->getX(), j= initial->getY();
    return (stateMatrix[i])[j];
}

State<Point*>* Matrix::getGoalState() {
    int i = goal->getX(), j= goal->getY();
    return (stateMatrix[i])[j];
}

bool Matrix::isGoalState(State<Point*>* state) {
    return ((state->getState()->getX() == goal->getX())
    && (state->getState()->getY()) == goal->getY());
}

vector<State<Point*> *> Matrix::getAllPosibleState(State<Point*> *state) {
    vector<State<Point*>*> allNeigth;
    int i = state->getState()->getX(), j = state->getState()->getY();
    // create the states of the neighbors
    if (i+1 < stateMatrix.size() && (matrix[i+1])[j] != -1){
        State<Point*>* downState = (stateMatrix[i+1])[j];
        allNeigth.push_back(downState);
    }
    if (i-1 >=0 && (matrix[i-1])[j] != -1){
        State<Point*>* upState = (stateMatrix[i-1])[j];
        allNeigth.push_back(upState);
    }
    if (j+1<stateMatrix.front().size() && (matrix[i])[j+1] != -1){
        State<Point*>* rightState = (stateMatrix[i])[j+1];
        allNeigth.push_back(rightState);
    }
    if (j-1 >=0 && (matrix[i])[j-1] != -1){
        State<Point*>* leftState = (stateMatrix[i])[j-1];
        allNeigth.push_back(leftState);
    }


    return allNeigth;
}