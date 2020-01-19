//
// Created by noa on 17/01/2020.
//

#ifndef DFS_DFSSREARCH_H
#define DFS_DFSSREARCH_H

// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include<iostream>
#include<list>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class DfsSearch
{
    // No. of vertices
    int V;

    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;

    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    DfsSearch(int V);   // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

#endif //DFS_DFSSREARCH_H
