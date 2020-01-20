//
// Created by noa on 19/01/2020.
//

#ifndef DFS_BESTFIRSTSEARCH_H
#define DFS_BESTFIRSTSEARCH_H

#include "State.h"
#include "Searchable.h"
#include <queue>
#include <string>

using namespace std;

template <class T>
class BestFirstSearch {
    queue<State<T>> openList;
    void sortOpenList();
    string backTrace();
public:
    string search(Searchable<T> searchable);
};


#endif //DFS_BESTFIRSTSEARCH_H
