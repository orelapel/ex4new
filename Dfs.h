//
// Created by noa on 21/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H
#include <string>
#include "Searchable.h"
#include <stack>
#include <algorithm>
#include "Searcher.h"

using namespace std;
template <class T>
class Dfs :public Searcher<T>{
private:
    int numberOfStates;
public:
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

    string search(Searchable<T>* searchable){
        stack<State<T>*> stackForDfs;
        State<T> *curr;
        curr = searchable->getInitialState();;
        curr->setTraceCost(curr->getCost());
        stackForDfs.push(curr);
        //vector<State<T>*> isColored;
        vector<State<T>*> succerssors;
        while (!stackForDfs.empty() &&!searchable->isGoalState(curr)) {
            curr = stackForDfs.top();
            stackForDfs.pop();
//            isColored.push_back(curr);
            curr->setColor(yellow);
            succerssors = searchable->getAllPosibleState(curr);
            for (State<T>* succerssor:succerssors){
                if(succerssor->getColor()==white){
                    succerssor->setColor(yellow);
                    if(!searchable->isGoalState(succerssor)) {
                        succerssor->setTraceCost(curr->getTraceCost() + succerssor->getCost());
                        succerssor->setCameFrom(curr);
                        stackForDfs.push(succerssor);
                    }
                    else {
                        succerssor->setTraceCost(curr->getTraceCost() + succerssor->getCost());
                        succerssor->setCameFrom(curr);
                        break;
                    }
                }
            }
        }
        return createPath(searchable);
    }

    Searcher<T>* clone() override {
        return new Dfs();
    }
    int getNumOfNodesEvaluated() {
        return numberOfStates;
    }
};


#endif //EX4_DFS_H
