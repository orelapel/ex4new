//
// Created by noa on 19/01/2020.
//

#ifndef DFS_VERTEX_H
#define DFS_VERTEX_H


class Vertex {
private:
    int cost;
    Vertex *v;
public:
    Vertex(int newCost,Vertex *newV){
        cost= newCost;
        v = newV;
    }
    int getCost();
    Vertex* getVertex();
    void setCost(int newCost);
    void setVertex(Vertex* newVertex);
};


#endif //DFS_VERTEX_H
