//
// Created by noa on 17/01/2020.
//

#include "DfsSearch.h"
DfsSearch::DfsSearch(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void DfsSearch::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void DfsSearch::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void DfsSearch::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}