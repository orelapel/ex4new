//
// Created by noa on 13/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <istream>
#include <iostream>
using namespace std;
class ClientHandler {
public:
    virtual void handleClient(int socket) = 0;
};

#endif //EX4_CLIENTHANDLER_H
