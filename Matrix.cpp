//
// Created by orelapel on 1/19/20.
//

#include "Matrix.h"

Matrix::Matrix(vector<vector<double>>* matrixProblem,Point* intialState,Point* goalState) {
    matrix = matrixProblem;
    initial = intialState;
    goal = goalState;
}

void Matrix::initialStateMatrix() {
    int i=0,j;
    for (std::vector<vector<double>>::iterator it = matrix->begin(); it != matrix->end(); ++it) {
        j=0;
        vector<State<Point>*> stateVector;
        for (std::vector<double>::iterator itIn = (*it).begin(); itIn != (*it).end(); ++itIn) {
            stateVector.push_back(new State<Point>(new Point(i,j), NULL, (*itIn)));
            j++;
        }
        stateMatrix.push_back(stateVector);
        i++;
    }
}

State<Point>* Matrix::getInitialState() {
    int i = initial->getX(), j= initial->getY();
    return (stateMatrix[i])[j];
}

bool Matrix::isGoalState(State<Point>* state) {
    return goal == state->getState();
}

vector<State<Point> *> Matrix::getAllPosibleState(State<Point> *state) {
    vector<State<Point>*> allNeigth;
    int i = state->getState()->getX(), j = state->getState()->getY();
    // create the states of the neighbors
    if (j+1<stateMatrix.front().size()){
        State<Point>* rightState = (stateMatrix[i])[j+1];
        rightState->setCameFrom(state);
        rightState->setTraceCost(state->getTraceCost() + rightState->getCost());
        allNeigth.push_back(rightState);
    }
    if (j-1 >=0){
        State<Point>* leftState = (stateMatrix[i])[j-1];
        leftState->setCameFrom(state);
        leftState->setTraceCost(state->getTraceCost() + leftState->getCost());
        allNeigth.push_back(leftState);
    }
    if (i-1 >=0){
        State<Point>* upState = (stateMatrix[i-1])[j];
        upState->setCameFrom(state);
        upState->setTraceCost(state->getTraceCost() + upState->getCost());
        allNeigth.push_back(upState);
    }
    if (i+1 < stateMatrix.size()){
        State<Point>* downState = (stateMatrix[i+1])[j];
        downState->setCameFrom(state);
        downState->setTraceCost(state->getTraceCost() + downState->getCost());
        allNeigth.push_back(downState);
    }
    return allNeigth;
}