cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex4 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Searcher.h Searchable.h State.h StringReverser.cpp StringReverser.h BfsSearch.cpp BfsSearch.h BestFirstSearch.cpp BestFirstSearch.h DfsSearch.cpp DfsSearch.h Dfs.h SolverAdapter.cpp SolverAdapter.h Bfs.h)
