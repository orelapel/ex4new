//
// Created by noa on 13/01/2020.
//

#include "MyTestClientHandler.h"
#include "string"
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include "Solver.h"
#include "StringReverser.h"

//template <class Solution, class Problem>
 void MyTestClientHandler::handleClient(int socket) {
     char buffer[1]={0};
     string line;
    CacheManager<string> *cache = new CacheManager<string>(10);
     while(read( socket , buffer, 1)>0){
         while(buffer[0]!='\n') {
             line += buffer[0];
             read( socket , buffer, 1);
         }
         if (cache->isSoulutaionExist(line)){
             string sol = cache->get(line);
             int length = sol.length();
             char lineToChar[length+1];
             strcpy(lineToChar,sol.c_str());
             send(socket,lineToChar,length+1,0);
         }else {
             Solver<string,string> *stringReverse = new StringReverser();
             string sol = stringReverse->solve(line);
             cache->insert(line, sol);
             int length = sol.length();
             char lineToChar[length+1];
             strcpy(lineToChar,sol.c_str());
             send(socket,lineToChar,length+1,0);
         }
    }
}