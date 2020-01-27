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
#include "FileCacheManager.h"

void MyTestClientHandler::handleClient(int socket) {
     char buffer[1]={0};
     string line;
    CacheManager<string> *cache = new FileCacheManager<string>(10);
     while(read( socket , buffer, 1)>0){
         while(buffer[0]!='\n') {
             line += buffer[0];
             read( socket , buffer, 1);
         }
         int len = line.length();
         char lineChar[len+1];
         strcpy(lineChar,line.c_str());
         if (strcmp(lineChar,"end")==0){
             break;
         }
         if (cache->isSoulutaionExist(line)){
             string sol = cache->get(line);
             int length = sol.length();
             char lineToChar[length+1];
             strcpy(lineToChar,sol.c_str());
             send(socket,lineToChar,length+1,0);
             cout<<sol<<endl;
         } else {
             Solver<string,string> *stringReverse = new StringReverser();
             string sol = stringReverse->solve(line);
             cache->insert(line, sol);
             int length = sol.length();
             char lineToChar[length+1];
             strcpy(lineToChar,sol.c_str());
             send(socket,lineToChar,length+1,0);
             cout<<sol<<endl;
         }
         line = "";
    }
}

MyTestClientHandler* MyTestClientHandler::clone() {
    return new MyTestClientHandler(solve->clone(),cashe->clone());
}