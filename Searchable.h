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
    State<T> getInitialState();
    bool isGoalState(State<T> state);
    vector<State<T>> getAllPosibleState(State<T> state);
};
#endif //EX4_SEARCHABLE_H
