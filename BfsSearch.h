//
// Created by orelapel on 1/17/20.
//

#ifndef EX4_BFSSEARCH_H
#define EX4_BFSSEARCH_H


#include<iostream>
#include <list>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class BfsSearch {
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    BfsSearch(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);
};


#endif //EX4_BFSSEARCH_H
