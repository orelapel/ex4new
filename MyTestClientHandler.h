//
// Created by noa on 13/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

//template <class Solution, class Problem>
class MyTestClientHandler: public ClientHandler {
    Solver *solve;
    CacheManager<string> *cashe;
public:
    void handleClient(int socket);
    MyTestClientHandler(Solver *solver, CacheManager<string> *myCashe) {
        solve = solver;
        cashe = myCashe;
    }
};


#endif //EX4_MYTESTCLIENTHANDLER_H
