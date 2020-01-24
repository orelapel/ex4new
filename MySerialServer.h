//
// Created by noa on 13/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer: public server_side::Server{
    bool shouldStop = false;
    int socketfd;
public:
    int start(int port, ClientHandler *clientHandler);
    int startThread(int port, ClientHandler *clientHandler);
    void stop();
};


#endif //EX4_MYSERIALSERVER_H
