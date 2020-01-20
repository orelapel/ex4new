//
// Created by orelapel on 1/19/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include "Matrix.h"

class MyClientHandler: public ClientHandler {
private:
    CacheManager<Matrix,string> *cache;


public:
    void handleClient(int socket);
};


#endif //EX4_MYCLIENTHANDLER_H
