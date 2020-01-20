//
// Created by orelapel on 1/19/20.
//

#include "MyClientHandler.h"
#include "string"
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <vector>
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

void MyClientHandler::handleClient(int socket) {
    char buffer[1]={0};
    string line;
    char* value;
    int i=0,j=0;
    bool isFirst = true;
    Point *initState, *goalState;
    vector<string> lines;
    CacheManager<string> *cache = new FileCacheManager<string>(10);
    while(read( socket , buffer, 1)>0){
        while(buffer[0]!='\n') {
            line += buffer[0];
            read( socket , buffer, 1);
        }
        lines.push_back(line);
        int len = line.length();
        char lineChar[len+1];
        strcpy(lineChar,line.c_str());
        if (strcmp(lineChar,"end")==0){
            break;
        } else if (len == 3 && isFirst) {
//            initState = std::make_pair(lineChar[0]-'0', lineChar[2]-'0') ;
            initState = new Point(lineChar[0]-'0', lineChar[2]-'0');
            isFirst = false;
        } else if (len == 3 && !isFirst){
            initState = new Point(lineChar[0]-'0', lineChar[2]-'0');
//            goalState = std::make_pair(lineChar[0]-'0', lineChar[2]-'0') ;
        }
//        if (cache->isSoulutaionExist(line)){
//            string sol = cache->get(line);
//            int length = sol.length();
//            char lineToChar[length+1];
//            strcpy(lineToChar,sol.c_str());
//            send(socket,lineToChar,length+1,0);
//            cout<<sol<<endl;
//        } else {
//            Solver *stringReverse = new StringReverser();
//            string sol = stringReverse->solve(line);
//            cache->insert(line, sol);
//            int length = sol.length();
//            char lineToChar[length+1];
//            strcpy(lineToChar,sol.c_str());
//            send(socket,lineToChar,length+1,0);
//            cout<<sol<<endl;
//        }
        line = "";
    }
    vector<vector<double>>* matrix;
    for (std::vector<string>::iterator it = lines.begin(); it != lines.end(); ++it) {
        vector<double> lineVector;
        int lenLine = (*it).length();
        char lineInt[lenLine+1];
        strcpy(lineInt,line.c_str());
        value= strtok (lineInt," ,");
        while (value!=NULL) {
            lineVector.push_back(stoi(value));
            value = strtok(NULL, " ,");
        }
        matrix->push_back(lineVector);
    }
    solver->solve(new Matrix(matrix, initState,goalState));
}