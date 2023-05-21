
#include "Point.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
using namespace std;
namespace ariel{}

double Point :: distance(Point other){
    double deltaX = (other.getX()) - this->x;
    double deltaY = (other.getY()) - this->y;
    double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    return distance;
}

Point Point:: moveTowards(Point source ,Point destination , double distance){
    if (distance < 0){
        throw invalid_argument("distance needs to be positive");
    }
    double dis = source.distance(destination);
    
    if (dis < distance)
        return destination;
    
    else{
        double mul = distance / dis;
        double delta_x = destination.getX() - source.getX();
        double delta_y = destination.getY() - source.getY();
        
        double new_X = source.x + delta_x * mul;
        double new_Y = source.y + delta_y * mul;
        return Point(new_X, new_Y);
    }

}   

double Point::getY(){
    return this->y;
}

double Point::getX(){
    return this->x;
}

void Point::setX(double num){
    this->x = num;
}

void Point::setY(double num){
    this->y = num;
}