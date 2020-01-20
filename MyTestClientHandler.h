//
// Created by noa on 13/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

//template <class Problem, class Solution>
class MyTestClientHandler: public ClientHandler {
    Solver<string ,string> *solve;
    CacheManager<string,string> *cashe;
public:
    void handleClient(int socket);
    MyTestClientHandler(Solver<string,string> *solver, CacheManager<string,string> *myCashe) {
        solve = solver;
        cashe = myCashe;
    }
};


#endif //EX4_MYTESTCLIENTHANDLER_H
