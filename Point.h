//
// Created by orelapel on 1/19/20.
//

#ifndef EX4_POINT_H
#define EX4_POINT_H

#include "string"
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int numX,int numY);
    int getX();
    int getY();
    void setX(int numX);
    void setY(int numY);
    string toString();
    Point* clone();
};

#endif //EX4_POINT_H
