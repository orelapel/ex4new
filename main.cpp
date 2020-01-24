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
#include "AStarSearch.h"

namespace boot {
    class Main;
}

class boot::Main{
public:
    static int main(int port) {
        try {
            MySerialServer *mySerial = new MySerialServer();
            Searcher<Point*>* searcher = new AStarSearch<Point*>();
            Solver<Matrix*, string> *solverAdapter = new SolverAdapter<Point*>(searcher);
            CacheManager<string> *fileCashe = new FileCacheManager<string>(10);
            ClientHandler *ch = new MyClientHandler(fileCashe,solverAdapter);
            mySerial->start(port,ch);
            mySerial->stop();

//            vector<vector<double>> maze = {{1,3,1},
//                                           {2,-1,1},
//                                           {4,5,0}};


//            vector<vector<double>> maze = {{5,-1,0,0,0,0},
//                                           {2,8,4,9,0,0},
//                                           {0,-1,1,-1,6,7},
//                                           {0,0,0,3,-1,4},
//                                           {0,0,0,1,-1,4},
//                                           {0,0,0,1,3,4}};
//            Matrix* matrix = new Matrix(maze, new Point(0,0), new Point(5,5));
//            cout<<solverAdapter->solve(matrix)<<endl;


//

//            Solver<vector<vector<vector<double>>*, string> = new SolverAdapter();
//            StringReverser *reverser = new StringReverser();

//            ClientHandler *ch = new MyClientHandler();
//            ClientHandler *ch = new MyTestClientHandler(reverser, fileCashe);
//            mySerial->start(port, ch);
//            mySerial->stop();
            return 0;
        }
        catch (const char * e){
            cout<<e<<endl;
        }

    }
};
int main(int argc,char* argv[]) {
    boot::Main::main(atoi(argv[1]));
    return 0;
}

