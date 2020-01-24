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
#include "StateComperator.h"
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

template <class T>
class BestFirstSearch: public Searcher<T> {
    priority_queue<State<T>*, vector<State<T>*>, StateComperator<T>> openList;
    unordered_set<State<T>*> closed;
    int numberOfStates;
public:
    string search(Searchable<T>* searchable) {
        State<T>* init = searchable->getInitialState();
        openList.push(init);
        searchable->getInitialState()->setTraceCost(searchable->getInitialState()->getCost());
        while (openList.size()>0) {
            State<T>* n = openList.top();
            openList.pop();
            closed.insert(n);
            if (searchable->isGoalState(n)) {
//                cout<<backTrace(closed)<<endl;
                return createPath(searchable);
            }

            vector<State<T>*> succerssors = searchable->getAllPosibleState(n);
            for (typename std::vector<State<T>*>::iterator it = succerssors.begin(); it != succerssors.end(); ++it) {
                if (closed.find(*it) == closed.end() && !findInOpenList(*it)) {
                    (*it)->setCameFrom(n);
                    (*it)->setTraceCost(n->getTraceCost() + (*it)->getCost());
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
                    openList.push(temp);
                    while (!tempStack.empty()){
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
    int getNumOfNodesEvaluated(){
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


#endif //DFS_BESTFIRSTSEARCH_H
