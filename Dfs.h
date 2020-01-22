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
    //check i do nothing with this
    double costOfTrace;
public:
    string createPath(Searchable<T>* searchable) {
        string path = "";
        State<T> *currentState = searchable->getGoalState();
        stack<string> stackForPath;
        int i = currentState->getState()->getX();
        int j = currentState->getState()->getY();
        int iCameFrom,jCameFrom;
//        while (currentState!=searchable.getInitialState()) {
        while (currentState !=nullptr && currentState->getCameFrom()!= nullptr){
                path = path+"(" + to_string(currentState->getTraceCost()) +"),";
                currentState = currentState->getCameFrom();
                iCameFrom = currentState->getState()->getX();
                jCameFrom = currentState->getState()->getY();
                if (i<iCameFrom){
                    path = "Up ";
                }
                else if (i>iCameFrom){
                    path = "Down ";
                }
                else if (j<jCameFrom){
                    path = "Left ";
                }
                else if(j>jCameFrom){
                    path = "Right ";
                }
                stackForPath.push(path);
                path="";
        }
        string returnString="";
        while(!stackForPath.empty()) {
            //add to the string of the path we return back
            returnString = returnString + stackForPath.top();
            //remove this element from the stack after we use it
            stackForPath.pop();
        }
        return path;
    }

    string search(Searchable<T>* searchable){
        numberOfStates=0;
        stack<State<T>*> stackForDfs;
        State<T> *curr;
        curr = searchable->getInitialState();;
        curr->setTraceCost(curr->getCost());
        stackForDfs.push(curr);
        vector<State<T>*> isColored;
        vector<State<T>*> succerssors;
        while (!stackForDfs.empty() &&!isGoalState(curr)) {
            curr = stackForDfs.top();
            numberOfStates++;
            stackForDfs.pop();
            isColored.push_back(curr);
            succerssors = searchable->getAllPosibleState(curr);
            //for (typename std::vector<State<T> *>::iterator it = succerssors.begin(); it != succerssors.end(); ++it) {
            for (State<T>* succerssor:succerssors){
                if ((std::find(isColored.begin(), isColored.end(), succerssor) != isColored.end())&&(succerssor->getCost()!=-1)) {
                    if(!isgoalState(succerssor)) {
                        succerssor->setTraceCost(curr->getTraceCost() + succerssor->getCost());
                        succerssor->setCameFrom(curr);
                        stackForDfs.push(succerssor);
                    }
                    else {
                        //curr = succerssor;
                        break;
                    }
                }
            }
        }
        return createPath(searchable);
    }
    int getNumOfNodesEvaluated() {
        return numberOfStates;
    }
};


#endif //EX4_DFS_H
