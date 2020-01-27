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
    double hAstar;
    State<T>* cameFrom;
    T myState;
    int colorOfState;
public:
    enum color { white =1, yellow=2};
    State(T state, State<T>* s, double c) {
        myState = state;
        cameFrom = s;
        cost = c;
        traceCost = std::numeric_limits<int>::max();
        hAstar = std::numeric_limits<int>::max();
        colorOfState =white;
    }
    void setHAstar(double f){
        hAstar = f;
    }
    double getHAstar(){
        return hAstar;
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
    void setColor(int color) {
        colorOfState = color;
    }
    int getColor() {
        return colorOfState;
    }
};

#endif //EX4_STATE_H
