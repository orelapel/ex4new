//
// Created by noa on 13/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H
#include <limits>
template <class T>
class State{
    double cost;
    double traceCost;
    State<T>* cameFrom;
    T* myState;
public:
    State(T* state, State<T>* s, double c) {
        myState = state;
        cameFrom = s;
        cost = c;
        traceCost = std::numeric_limits<int>::max();
    }
    T* getState(){
        return myState;
    }
    double getCost(){
        return cost;
    }
    T* getCameFrom() {
        return cameFrom;
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
};

#endif //EX4_STATE_H
