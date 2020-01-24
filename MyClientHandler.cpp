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

MyClientHandler::MyClientHandler(CacheManager<string> *c, Solver<Matrix *, string> *s) {
    cache = c;
    solver = s;
}
void MyClientHandler::handleClient(int socket) {
    char buffer[1]={0};
    string line;
    char* value;
    int i=0,j=0;
    bool isFirst = true;
    Point *initState, *goalState;
    vector<string> lines;
//    CacheManager<string> *cache = new FileCacheManager<string>(10);
    bool stillData = true;
    while(stillData && read( socket , buffer, 1)>0) {
        while(buffer[0]!='\n') {
            line += buffer[0];
            read( socket , buffer, 1);
        }
        int len = line.length();
        char lineChar[len+1];
        strcpy(lineChar,line.c_str());
        if (strcmp(lineChar,"end")==0){
            stillData = false;
        } else {
            lines.push_back(line);
        }
        line = "";
    }
    initState = new Point(0,0);
    goalState = new Point(0,0);
    string pointGoal = lines.back();
    int lenPoint = pointGoal.length();
    char lineGoal[lenPoint+1];
    strcpy(lineGoal,pointGoal.c_str());
    char* x = strtok (lineGoal," ,"), *y;
    if (x !=NULL) {
        goalState->setX(stod(x));
        y = strtok(NULL, " ,");
        if (y!=NULL){
            goalState->setY(stod(y));
        }
    }
    lines.pop_back();
    string pointInit = lines.back();
    lenPoint = pointInit.length();
    char lineInit[lenPoint+1];
    strcpy(lineInit,pointInit.c_str());
    x = strtok (lineInit," ,");
    if (x !=NULL) {
        initState->setX(stod(x));
        y = strtok(NULL, " ,");
        if (y!=NULL){
            initState->setY(stod(y));
        }
    }
    lines.pop_back();

    vector<vector<double>> matrix;
    int index = 0;
    string bigLine;
    for (std::vector<string>::iterator it = lines.begin(); it != lines.end(); ++it) {
        bigLine += (*it);
        vector<double> lineVector;
        int lenLine = (*it).length();
        char lineInt[lenLine+1];
        strcpy(lineInt,(*it).c_str());
        value = strtok (lineInt," ,");
        int k=0;
        while (value!=NULL) {
            lineVector.push_back(stod(value));
            value = strtok(NULL, " ,");
        }
        matrix.push_back(lineVector);
    }
    Matrix *matrixSearchabe = new Matrix(matrix, initState, goalState);
    hash<string> hash;
    string bigLineHash = to_string(hash(bigLine));
    string sol;
    if (cache->isSoulutaionExist(bigLineHash)){
        sol = cache->get(bigLineHash);
        cout<<sol<<endl;
    } else {
        sol = solver->solve(matrixSearchabe);
        cache->insert(bigLineHash, sol);
        cout << sol << endl;
    }
    int length = sol.length();
    char lineToChar[length+1];
    strcpy(lineToChar,sol.c_str());
    send(socket,lineToChar,length+1,0);
}