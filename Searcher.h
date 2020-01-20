//
// Created by noa on 13/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
#include "string"


template <class T>
class Searcher:public Searchable<T>{
    virtual string Search(Searchable<T> searchable)=0;
    virtual int getNumOfNodesEvaluated()=0;
};
#endif //EX4_SEARCHER_H
