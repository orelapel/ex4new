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

MyClientHandler::MyClientHandler(CacheManager<Matrix *> *c, Solver<Matrix *, string> *s) {
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
    CacheManager<string> *cache = new FileCacheManager<string>(10);
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
    // TODO check if always the matrix is squer
    vector<vector<double>> matrix( lines.size() , vector<double> (lines.size()));
    int index = 0;
    for (std::vector<string>::iterator it = lines.begin(); it != lines.end(); ++it) {
        int lenLine = (*it).length();
        char lineInt[lenLine+1];
        strcpy(lineInt,(*it).c_str());
        value = strtok (lineInt," ,");
        int k=0;
        while (value!=NULL) {
            matrix[index][k]=(stod(value));
            value = strtok(NULL, " ,");
            k++;
        }
        index++;
//        matrix->push_back(lineVector);
    }
    Matrix *matrixSearchabe = new Matrix(matrix, initState, goalState);
    matrixSearchabe->initialStateMatrix();
    cout<<solver->solve(matrixSearchabe)<<endl;
}