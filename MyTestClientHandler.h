//
// Created by noa on 13/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

template <class Solution, class Problem>
class MyTestClientHandler: public ClientHandler {
    Solver *s;
    CacheManager<Solution,Problem> *cashe;
};


#endif //EX4_MYTESTCLIENTHANDLER_H
