//
// Created by noa on 13/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include <stack>
#include "Searchable.h"
#include "string"

enum color { white =1, yellow=2};
template <class T>
class Searcher{
public:
    virtual string search(Searchable<T>* searchable)=0;
    virtual int getNumOfNodesEvaluated()=0;
    virtual string createPath(Searchable<T>* searchable)=0;
    virtual Searcher* clone()=0;
};
#endif //EX4_SEARCHER_H
