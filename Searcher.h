//
// Created by noa on 13/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"

template <class T,class Solution,class Problem>
class Searcher:public Searchable<T>{
    Solution Search(Searchable<T> searchable);
};
#endif //EX4_SEARCHER_H
