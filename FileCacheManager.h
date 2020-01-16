//
// Created by noa on 13/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H
#include "CacheManager.h"
#include "string"

template <typename T>
class FileCacheManager:public CacheManager<T> {
public:
    FileCacheManager(unsigned int capacity):CacheManager<string>(capacity){}
};


#endif //EX4_FILECACHEMANAGER_H
