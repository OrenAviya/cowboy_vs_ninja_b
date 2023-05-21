#pragma once 
#include <iostream>
#include <stdlib.h>
# include "Point.hpp"

using namespace std;
namespace ariel{}

class Character{
    private:
    
        const char* Name;
        int Hit_points;
    
    protected:
        Point Location;
        int type;
    
    public:
    bool inTeam;
    //constructors
    Character();
    Character(const char* name , Point location , int hitPoints);

    //getters :
    const char* getName();
    virtual Point getLocation();
    int getHitPoints();
    void setHitpoints(int number);
    int getType();

    //methods:
        virtual bool isAlive();
        virtual double distance(Character *other);
        virtual void hit(int number);
        virtual std::string print();
        // virtual ~Character() = default;
        Character operator =(Character *some);
};


class Ninja: public Character{
private :
        int speed;
        
    public:
     // constructors:
    Ninja(const char* name, Point location , int hitPoints, int speedtype);
    Ninja();

        void move(Character *enemy);
        void slash(Character *enemy);
        virtual string print();
        // virtual ~Ninja() = default;
};