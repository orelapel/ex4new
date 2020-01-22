//
// Created by noa on 19/01/2020.
//

#ifndef DFS_BESTFIRSTSEARCH_H
#define DFS_BESTFIRSTSEARCH_H

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
class BestFirstSearch: public Searcher<T> {
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
                curr = currState->getTraceCost();
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
                curr = currState->getTraceCost();
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
public:
    string search(Searchable<T>* searchable) {
        State<T>* init = searchable->getInitialState();
        openList.push_back(init);
        searchable->getInitialState()->setTraceCost(searchable->getInitialState()->getCost());
        while (openList.size()>0){
            sortOpenList();
            State<T>* n = openList.front();
            openList.pop_front();
            closed.insert(n);
            if (searchable->isGoalState(n)) {
//                cout<<backTrace(closed)<<endl;
                return backTrace(closed);
            }

            vector<State<T>*> succerssors = searchable->getAllPosibleState(n);
            for (typename std::vector<State<T>*>::iterator it = succerssors.begin(); it != succerssors.end(); ++it) {
                if (closed.find(*it) == closed.end() && find(openList.begin(), openList.end(), (*it)) == openList.end()) {
                    openList.push_back(*it);
                } else if (find(openList.begin(), openList.end(), (*it)) != openList.end() && (*it)->getTraceCost() > n->getTraceCost() + (*it)->getCost()) {
                    stack<State<T>*> tempStack;
                    while (openList.front() != (*it)) {
                        tempStack.push(openList.front());
                        openList.pop_front();
                    }
                    State<T>* temp = openList.front();
                    openList.pop_front();
                    temp->setTraceCost(n->getTraceCost() + (*it)->getCost());
                    temp->setCameFrom(n);
                    openList.push_back(temp);
                    while (!tempStack.empty()){
                        openList.push_back(tempStack.top());
                        tempStack.pop();
                    }
                }
            }
        }
    }
    int getNumOfNodesEvaluated(){
        return closed.size();
    }
};


#endif //DFS_BESTFIRSTSEARCH_H
