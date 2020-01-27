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
    int numberOfStates;
public:
    string search(Searchable<T>* searchable) {
        priority_queue<State<T>*, vector<State<T>*>, StateComperator<T>> openList;
        unordered_set<State<T>*> closed;
        State<T>* init = searchable->getInitialState();
        openList.push(init);
        searchable->getInitialState()->setTraceCost(searchable->getInitialState()->getCost());
        while (openList.size()>0) {
            State<T>* n = openList.top();
            openList.pop();
            closed.insert(n);
            if (searchable->isGoalState(n)) {
                return createPath(searchable);
            }

            vector<State<T>*> succerssors = searchable->getAllPosibleState(n);
            for (typename std::vector<State<T>*>::iterator it = succerssors.begin(); it != succerssors.end(); ++it) {
                // if it is a new state
                if (closed.find(*it) == closed.end() && !findInOpenList((*it),openList)) {
                    (*it)->setCameFrom(n);
                    (*it)->setTraceCost(n->getTraceCost() + (*it)->getCost());
                    openList.push(*it);
                    // if it was before in openList but now the costTrace is better
                } else if (findInOpenList((*it),openList) && (*it)->getTraceCost() > n->getTraceCost() + (*it)->getCost()) {
                    stack<State<T>*> tempStack;
                    // remove from the openList to stack until we get to the state we want
                    while (openList.top() != (*it)) {
                        tempStack.push(openList.top());
                        openList.pop();
                    }
                    // change it with new details
                    State<T>* temp = openList.top();
                    openList.pop();
                    temp->setTraceCost(n->getTraceCost() + (*it)->getCost());
                    temp->setCameFrom(n);
                    // push back the states we took out from the openList
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
        cout<<"no problem yet"<<endl;
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

            // find the direction we came from
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
            // find the trace cost until this state
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
        numberOfStates=numberOfStates+1;
        returnString+="\nnumber of nodes evaluated: ";
        returnString+=to_string(numberOfStates);
        returnString+="\n";
        return returnString;
    }

    Searcher<T>* clone () override {
        return new BestFirstSearch();
    }
    int getNumOfNodesEvaluated() {
        return numberOfStates;
    }
    bool findInOpenList(State<T>* state,priority_queue<State<T>*, vector<State<T>*>, StateComperator<T>> openList) {
        stack<State<T>*> temp;
        while (!openList.empty()) {
            temp.push(openList.top());
            // if the state exist in the openList
            if (state==openList.top()) {
                temp.pop();
                // return the states to the openList
                while (!temp.empty()){
                    openList.push(temp.top());
                    temp.pop();
                }
                return true;
            }
            openList.pop();
        }
        // return the states to the openList
        while (!temp.empty()){
            openList.push(temp.top());
            temp.pop();
        }
        return false;
    }
};


#endif //DFS_BESTFIRSTSEARCH_H
