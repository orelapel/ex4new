//
// Created by noa on 27/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include <iostream>
#include <vector>
#include "MySerialServer.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "Matrix.h"
#include "MyClientHandler.h"
#include "SolverAdapter.h"
#include "BestFirstSearch.h"
#include "Bfs.h"
#include "AStarSearch.h"
#include "Dfs.h"
#include "MyParallelServer.h"

namespace boot {
    class Main {
    public:
        int main(int port){
            try {
                MyParallelServer *myParallelServer = new MyParallelServer();
                Searcher<Point*>* searcher = new AStarSearch<Point*>();
                Solver<Matrix*, string> *solverAdapter = new SolverAdapter<Point*>(searcher);
                CacheManager<string> *fileCashe = new FileCacheManager<string>(10);
                ClientHandler *ch = new MyClientHandler(fileCashe,solverAdapter);
                myParallelServer->start(port,ch);
                myParallelServer->stop();
                return 0;
            }
            catch (const char * e){
                cout<<e<<endl;
            }
        }
    };
}
#endif //EX4_BOOT_H
