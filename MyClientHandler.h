//
// Created by orelapel on 1/19/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include "Matrix.h"
#include "Solver.h"

class MyClientHandler: public ClientHandler {
private:
    CacheManager<Matrix*> *cache;
    Solver<Matrix*,string> *solver;
public:
    void handleClient(int socket);
};


#endif //EX4_MYCLIENTHANDLER_H
