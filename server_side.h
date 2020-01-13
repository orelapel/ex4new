//
// Created by noa on 13/01/2020.
//

#ifndef EX4_SERVER_SIDE_H
#define EX4_SERVER_SIDE_H

#include "ClientHandler.h"

namespace sever_side {
    class Server {
    public:
        void open(int port,ClientHandler c);
        void stop();
    };
}
#endif //EX4_SERVER_SIDE_H
