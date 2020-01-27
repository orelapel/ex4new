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
    CacheManager<string> *cache;
    Solver<Matrix*,string> *solver;
public:
    MyClientHandler(CacheManager<string> *c, Solver<Matrix*,string> *s);
    void handleClient(int socket) override;
    MyClientHandler* clone();
};

#endif //EX4_MYCLIENTHANDLER_H
