//
// Created by noa on 19/01/2020.
//

#include "Vertex.h"

int Vertex::getCost() {
    return cost;
}
Vertex *Vertex:: getVertex(){
    return v;
}
void Vertex::setCost(int newCost) {
    cost=newCost;
}
void Vertex::setVertex(Vertex* newVertex){
    v = newVertex;
}
