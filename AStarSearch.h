//
// Created by orelapel on 1/22/20.
//

#ifndef EX4_ASTARSEARCH_H
#define EX4_ASTARSEARCH_H

#include "State.h"
//#include "Searchable.h"
#include "Searcher.h"
#include <deque>
#include <string>
#include <unordered_set>
#include <set>
#include "Point.h"
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
#include "StateComperator.h"
using namespace std;

template <class T>
class AStarSearch: public Searcher<T>{
    priority_queue<State<T>*, vector<State<T>*>, StateComperator<T>> openList;
    unordered_set<State<T>*> closed;
    int numberOfStates;

    double getH(State<T>* curr, State<T>* goal) {
        double x1 = curr->getState()->getX(), y1 = curr->getState()->getY();
        double x2 = goal->getState()->getX(), y2 = goal->getState()->getY();
        return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    }
public:
    string search(Searchable<T>* searchable) {
        State<T>* init = searchable->getInitialState();
        State<T>* goal = searchable->getGoalState();
        init->setTraceCost(searchable->getInitialState()->getCost());
        double hInit = getH(init, goal);
        init->setHAstar(hInit);
//        init->setF(init->getTraceCost() + hInit);
        openList.push(init);
        while (openList.size()>0) {
            State<T>* n = openList.top();
            openList.pop();
            closed.insert(n);
            if (searchable->isGoalState(n)) {
                return createPath(searchable);
            }
            vector<State<T>*> succerssors = searchable->getAllPosibleState(n);
            for (typename std::vector<State<T>*>::iterator it = succerssors.begin(); it != succerssors.end(); ++it) {
                if (closed.find(*it) == closed.end() && !findInOpenList(*it)) {
                    (*it)->setCameFrom(n);
                    (*it)->setTraceCost(n->getTraceCost() + (*it)->getCost());
                    double hSucc = getH((*it),goal);
                    (*it)->setHAstar(hSucc);
                    //(*it)->setF((*it)->getTraceCost() + hSucc);
                    openList.push(*it);
                } else if (findInOpenList(*it) && (*it)->getTraceCost() > n->getTraceCost() + (*it)->getCost()) {
                    stack<State<T>*> tempStack;
                    while (openList.top() != (*it)) {
                        tempStack.push(openList.top());
                        openList.pop();
                    }
                    State<T>* temp = openList.top();
                    openList.pop();
                    temp->setTraceCost(n->getTraceCost() + (*it)->getCost());
                    temp->setCameFrom(n);
                    double hSucc = getH((*it),goal);
                    temp->setHAstar(hSucc);
                    //temp->setF(n->getTraceCost() + (*it)->getCost());
                    temp->setCameFrom(n);
                    openList.push(temp);
                    while (!tempStack.empty()) {
                        openList.push(tempStack.top());
                        tempStack.pop();
                    }
                }
            }
        }
        return "no path exist";
    }

    string createPath(Searchable<T>* searchable) {
        numberOfStates=0;
        string path = "";
        State<T> *currentState = searchable->getGoalState();
        stack<string> stackForPath;
        int i,j;
        int iCameFrom,jCameFrom;
        double traceOfCurrentState =0;
        while (currentState !=nullptr && currentState->getCameFrom()!= nullptr){
            i = currentState->getState()->getX();
            j = currentState->getState()->getY();
            traceOfCurrentState = currentState->getTraceCost();
            currentState = currentState->getCameFrom();
            iCameFrom = currentState->getState()->getX();
            jCameFrom = currentState->getState()->getY();
            if (i<iCameFrom){
                path = path+"Up ";
            }
            else if (i>iCameFrom){
                path = path + "Down ";
            }
            else if (j<jCameFrom){
                path = path +"Left ";
            }
            else if(j>jCameFrom){
                path = path + "Right ";
            }
            path = path +"(" + to_string(traceOfCurrentState) + "), ";
            stackForPath.push(path);
            path="";
        }
        string returnString="";
        while(!stackForPath.empty()) {
            numberOfStates++;
            //add to the string of the path we return back
            returnString = returnString + stackForPath.top();
            //remove this element from the stack after we use it
            stackForPath.pop();
        }
        return returnString;
    }
    int getNumOfNodesEvaluated() {
        return numberOfStates;
    }
    bool findInOpenList(State<T>* state) {
        stack<State<T>*> temp;
        while (!openList.empty()) {
            temp.push(openList.top());
            if (state==openList.top()) {
                temp.pop();
                while (!temp.empty()){
                    openList.push(temp.top());
                    temp.pop();
                }
                return true;
            }
            openList.pop();
        }
        while (!temp.empty()){
            openList.push(temp.top());
            temp.pop();
        }
        return false;
    }
};
#endif //EX4_ASTARSEARCH_H