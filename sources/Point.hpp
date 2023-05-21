#pragma once 
#include <iostream>
#include <stdlib.h>

using namespace std;
namespace ariel{}
    class Point{
       private:
        double x ;
        double y ;

    public:
        //constructors:
        // regular
        Point(double coordinate_x , double coordinate_y): x(coordinate_x) , y(coordinate_y){}
       // empty
        Point():x(0) , y(0){}

        //getters, setters:
        double getY();
        double getX();
        void setX(double num);
        void setY(double num);

        //methods:
        double distance(Point other);
        void print();
        static Point moveTowards(Point source ,Point destination , double distance);



    };
