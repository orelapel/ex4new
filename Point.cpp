//
// Created by orelapel on 1/19/20.
//

#include "Point.h"
Point::Point(int numX,int numY){
   x = numX;
   y = numY;
}
int Point::getX() {
    return x;
}
int Point::getY() {
    return y;
}
void Point::setX(int numX){
    x = numX;
}
void Point::setY(int numY) {
    y = numY;
}
