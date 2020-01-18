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

template <typename T>
class CacheManager {
public:
    virtual void insert(string key, T obj) = 0;

    virtual T get(string key) =0;

    virtual void foreach(void (*func)(T &obj))=0;

    virtual bool isSoulutaionExist(T key)=0;
};

#endif //EX4_CACHEMANAGER_H
