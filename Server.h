//
// Created by noa on 13/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server;
}
class server_side::Server {
public:
    virtual int start(int port,ClientHandler *c)=0;
    virtual void stop()=0;
};
#endif //EX4_SERVER_H
