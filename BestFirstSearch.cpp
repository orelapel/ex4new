//
// Created by noa on 19/01/2020.
//

#include "BestFirstSearch.h"
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

template <class T>
string BestFirstSearch<T>::search(Searchable<T> searchable) {
    openList.push(searchable.getInitialState());
    searchable.getInitialState()->setTraceCost(searchable.getInitialState()->getCost());
    unordered_set<State<T>> closed = new unordered_set<State<T>>();
    while (openList.size()>0){
        sortOpenList();
        State<T> n = openList.pop();
        closed.insert(n);
        if (searchable.isGoalState(n)) {
            return ""; // backTrace
        }
        vector<State<T>> succerssors = searchable.getAllPosibleState();
        for (typename std::vector<State<T>>::iterator it = succerssors.begin(); it != succerssors.end(); ++it) {
            if (closed.find(*it) == closed.end() && find(openList.begin(), openList.end(), (*it)) == openList.end()) {
                openList.push(*it);
            } else if (find(openList.begin(), openList.end(), (*it)) != openList.end() && (*it).getTraceCost() > n.getTraceCost() + (*it).getCost()) {
                stack<State<T>> tempStack;
                while (openList.front() != (*it)) {
                    tempStack.push(openList.front());
                    openList.pop();
                }
                State<T> temp = openList.front();
                openList.pop();
                temp.setTraceCost(n.getTraceCost() + (*it).getCost());
                temp.setCameFrom(n);
                openList.push(temp);
                while (!tempStack.empty()){
                    openList.push(tempStack.top());
                    tempStack.pop();
                }
            }
        }
    }
}

template <class T>
void BestFirstSearch<T>::sortOpenList() {
    for (int i = 1; i <= openList.size(); i++) {
        // find the min_index
        int min_index = -1;
        State<T> minState=NULL;
        double min_val = INT_MAX;
        State<T> currState;
        double curr;
        int n = openList.size();
        for (int j = 0; j < n; j++) {
            currState = openList.front();
            curr = currState.getTraceCost();
            openList.pop();

            if (curr <= min_val && j <= openList.size() - i) {
                min_index = j;
                min_val = curr;
                minState = currState;
            }
            openList.push(currState);
        }

        n = openList.size();
        for (int i = 0; i < n; i++)
        {
            currState = openList.front();
            curr = currState.getTraceCost();
            openList.pop();
            if (i != min_index)
                openList.push(currState);
            else {
                minState = currState;
            }
        }
        openList.push(minState);
    }
}

template <class T>
string BestFirstSearch<T>::backTrace() {

}