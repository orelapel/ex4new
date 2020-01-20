//
// Created by noa on 13/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <fstream>
#include "string"
#include "list"
#include "iterator"
#include "unordered_map"
using namespace std;

template <class Problem>
class CacheManager {
public:
    virtual void insert(Problem key, string obj) = 0;

    virtual string get(Problem key) =0;

    virtual void foreach(void (*func)(string &obj))=0;

    virtual bool isSoulutaionExist(Problem key)=0;
};

#endif //EX4_CACHEMANAGER_H
