//
// Created by noa on 13/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H
#include <limits>
#include "string"
using namespace std;

template <class T>
class State{
    double cost;
    double traceCost;
    double fAstar;
    State<T>* cameFrom;
    T myState;
public:
    State(T state, State<T>* s, double c) {
        myState = state;
        cameFrom = s;
        cost = c;
        traceCost = std::numeric_limits<int>::max();
        fAstar = std::numeric_limits<int>::max();
    }
    void setF(double f){
        fAstar = f;
    }
    double getF(){
        return fAstar;
    }
    T getState() {
        return myState;
    }
    double getCost(){
        return cost;
    }
    void setCameFrom(State<T>* c){
        cameFrom = c;
    }
    void setTraceCost(double c){
        traceCost = c;
    }
    double getTraceCost(){
        return traceCost;
    }
    T getCameFromState() {
        return cameFrom->getState();
    }
    State<T>* getCameFrom(){
        return cameFrom;
    };

};

#endif //EX4_STATE_H
