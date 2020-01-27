//
// Created by noa on 23/01/2020.
//

#include "MyParallelServer.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <vector>

int MyParallelServer::runOnClient(int port, ClientHandler *clientHandler,int client_Socket) {
    clientHandler->handleClient(client_Socket);
    delete clientHandler;
}

int MyParallelServer::start(int port, ClientHandler *clientHandler) {
    vector<thread> vectorThreads;
    //create socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    struct timeval tv;
    tv.tv_sec = 60;
    tv.tv_usec = 0;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    //making socket listen to the port
    if (listen(socketfd, 20) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
    while (true) {
        int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                   (socklen_t *) &address);

        if (client_socket == -1) {
            std::cerr << "Error accepting client" << std::endl;
            break;
        }
        vectorThreads.push_back(thread(&MyParallelServer::runOnClient, this, port, clientHandler->clone(), client_socket));
    }
    for (std::thread & th : vectorThreads){
        th.join();
    }
}

void MyParallelServer::stop() {
    close(socketfd);
}