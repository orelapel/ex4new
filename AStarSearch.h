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
using namespace std;

template <class T>
class AStarSearch: public Searcher<T>{
    deque<State<T>*> openList;
    unordered_set<State<T>*> closed;
    void sortOpenList(){
        for (int i = 1; i <= openList.size(); i++) {
            // find the min_index
            int min_index = -1;
            State<T>* minState=NULL;
            double min_val = INT_MAX;
            State<T>* currState;
            double curr;
            int n = openList.size();
            for (int j = 0; j < n; j++) {
                currState = openList.front();
                curr = currState->getF();
                openList.pop_front();

                if (curr <= min_val && j <= openList.size() - i) {
                    min_index = j;
                    min_val = curr;
                    minState = currState;
                }
                openList.push_front(currState);
            }

            n = openList.size();
            for (int i = 0; i < n; i++)
            {
                currState = openList.front();
                curr = currState->getF();
                openList.pop_front();
                if (i != min_index)
                    openList.push_front(currState);
                else {
                    minState = currState;
                }
            }
            openList.push_front(minState);
        }
//        deque<State<T>*> temp;
//        for (int i = 1; i <= openList.size(); i++) {
//
//        }
    }
    string backTrace(unordered_set<State<T>*> closed){
        string trace = "";
        typename std::unordered_set<State<T>*>::iterator it;
        for (it=closed.begin(); it!=closed.end(); ++it) {
            Point* p = (*it)->getCameFromState();
            trace += p->toString();
        }
        return trace;
    }

    double getH(State<T>* curr, State<T>* goal) {
        double x1 = curr->getState().getX(), y1 = curr->getState().getY();
        double x2 = goal->getGoalState()->getState()->getX(), y2 = goal->getGoalState()->getState()->getY();
        return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    }

//    double getF(State<T>* curr, State<T>* goal) {
//        return getH(curr, goal) + curr->getTraceCost();
//    }
public:
    string search(Searchable<T>* searchable) {
        State<T>* init = searchable->getInitialState();
        State<T>* goal = searchable->getGoalState();
        init->setTraceCost(searchable->getInitialState()->getCost());
        double hInit = getH(init, goal);
        init->setF(init->getTraceCost() + hInit);
        openList.push_back(init);
        while (openList.size()>0) {
            sortOpenList();
            State<T>* n = openList.front();
            openList.pop_front();
            closed.insert(n);
            if (searchable->isGoalState(n)) {
                return createPath(searchable);
            }
            vector<State<T>*> succerssors = searchable->getAllPosibleState(n);
            for (typename std::vector<State<T>*>::iterator it = succerssors.begin(); it != succerssors.end(); ++it) {
                if (closed.find(*it) == closed.end() && find(openList.begin(), openList.end(), (*it)) == openList.end()) {
                    double hSucc = getH((*it),goal);
                    (*it)->setF((*it)->getTraceCost() + hSucc);
                    openList.push_front(*it);
                } else if (find(openList.begin(), openList.end(), (*it)) != openList.end() && (*it)->getTraceCost() > n->getTraceCost() + (*it)->getCost()) {
                    stack<State<T>*> tempStack;
                    while (openList.front() != (*it)) {
                        tempStack.push(openList.front());
                        openList.pop_front();
                    }
                    State<T>* temp = openList.front();
                    openList.pop_front();
                    temp->setF(n->getTraceCost() + (*it)->getCost());
                    temp->setCameFrom(n);
                    openList.push_front(temp);
                    while (!tempStack.empty()) {
                        openList.push_front(tempStack.top());
                        tempStack.pop();
                    }
                } else if (closed.find(*it) != closed.end() && (*it)->getTraceCost() > n->getTraceCost() + (*it)->getCost()){
                    State<T>* temp = closed.find(*it);
                    closed.erase(temp);
                    openList.push_front(temp);
                }
            }
        }
    }

    int getNumOfNodesEvaluated(){
        return closed.size();
    }
};
#endif //EX4_ASTARSEARCH_H