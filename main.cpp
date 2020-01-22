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

namespace boot {
    class Main;
}

class boot::Main{
public:
    static int main(int port) {
        try {
            MySerialServer *mySerial = new MySerialServer();
            Searcher<Point*>* searcher = new BestFirstSearch<Point*>();
            Solver<Matrix*, string> *solverAdapter = new SolverAdapter<Point*>(searcher);
            CacheManager<Matrix*> *fileCashe = new FileCacheManager<Matrix*>(10);
            ClientHandler *ch = new MyClientHandler(fileCashe,solverAdapter);
            mySerial->start(port,ch);


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

