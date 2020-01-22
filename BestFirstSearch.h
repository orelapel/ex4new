//
// Created by noa on 19/01/2020.
//

#ifndef DFS_BESTFIRSTSEARCH_H
#define DFS_BESTFIRSTSEARCH_H

#include "State.h"
#include "Searchable.h"
#include "Searcher.h"
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

template <class T>
class BestFirstSearch:public Searcher<T> {
    queue<State<T>> openList;
    void sortOpenList();
    string backTrace(unordered_set<State<T>> closed);
public:
    string search(Searchable<T>* searchable);
};


#endif //DFS_BESTFIRSTSEARCH_H
