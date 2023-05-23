
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
        // move to the closest point to the destination that you can reach
        double real = distance / dis;
        double delta_x = destination.getX() - source.getX();
        double delta_y = destination.getY() - source.getY();
        double newX = source.x + delta_x * real;
        double newY = source.y + delta_y * real;
        return Point(newX, newY);
    }

} 
void Point::print(){
cout<<" (" + to_string(this->getX()) + "," + to_string(this->getY()) + ")\n";
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