//
// Created by orelapel on 1/23/20.
//

#ifndef EX4_STATECOMPERATOR_H
#define EX4_STATECOMPERATOR_H

#include "State.h"

template <class T>
struct StateComperator{
    bool operator()(State<T> *left, State<T> *right){
        return (left->getTraceCost() + left->getHAstar()) > (right->getTraceCost() + right->getHAstar());
    }
};
#endif //EX4_STATECOMPERATOR_H
