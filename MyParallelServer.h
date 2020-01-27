//
// Created by noa on 23/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H


#include "Server.h"

class MyParallelServer: public server_side::Server{
    bool shouldStop = false;
    int socketfd;
public:
    int start(int port, ClientHandler *clientHandler);
//    int startThread(int port, ClientHandler *clientHandler);
    //int RunParallelOnTheClient(int port, ClientHandler *clientHandler);
    void stop();
    int runOnClient(int port, ClientHandler *clientHandler, int client_Socket);
};

#endif //EX4_MYPARALLELSERVER_H
