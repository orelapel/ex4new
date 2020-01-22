//
// Created by noa on 13/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "State.h"
#include <vector>
using namespace std;

template<class T>
class Searchable {
public:
    virtual State<T>* getInitialState()=0;
    virtual bool isGoalState(State<T>* state)=0;
    virtual vector<State<T>*> getAllPosibleState(State<T>* state)=0;
    virtual State<Point *> *getGoalState()=0;
};
#endif //EX4_SEARCHABLE_H
