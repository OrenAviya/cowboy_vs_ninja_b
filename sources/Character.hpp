#pragma once 
#include <iostream>
#include <stdlib.h>
# include "Point.hpp"

using namespace std;
namespace ariel{}

class Character{
   public:
    
        const char* Name;
        int Hit_points;
        bool inTeam;
        Point Location;
        int type;
    
    
    
    //constructors
    Character();
    Character(const char* name , Point location , int hitPoints);
    // Copy constructor
    Character(const Character& other) 
        : Name(other.Name), Hit_points(other.Hit_points),
          inTeam(other.inTeam), Location(other.Location),
          type(other.type) {}

    // Move constructor
    Character(Character&& other) noexcept
        : Name((other.Name)), Hit_points(other.Hit_points),
          inTeam(other.inTeam), Location((other.Location)),
          type(other.type) {
        other.Name = nullptr;
        other.Hit_points = 0;
        other.inTeam = false;
        other.type = 0;
    }
    //getters :
    const char* getName();
    virtual Point getLocation();
    int getHitPoints();
    void setHitpoints(int number);
    int getType();

    //methods:
         Character&operator=(Character&& other) noexcept;
         Character& operator=(const Character& other);
        virtual bool isAlive();
        virtual double distance(Character *other);
        virtual void hit(int number);
        virtual string print() ;
        virtual ~Character() = default;
        // virtual Character& operator =(Character *some);
};


class Ninja: public Character{
 public:
        int speed;
        
   
     // constructors:
    Ninja(const char* name, Point location , int hitPoints, int speedtype);
    Ninja();
    Ninja(const Ninja& other)
        : Character(other), speed(other.speed) {
    }

    // Copy assignment operator
    Ninja& operator=(const Ninja& other) {
        if (this != &other) {
            Character::operator=(other);
            speed = other.speed;
        }
        return *this;
    }

    // Move constructor
    Ninja(Ninja&& other) noexcept
        : Character(std::move(other)), speed(other.speed) {
        // No additional resources to move for 'Ninja'
    }

    // Move assignment operator
    Ninja& operator=(Ninja&& other) noexcept {
        if (this != &other) {
            Character::operator=((other));
            speed = other.speed;
            
        }
        return *this;
    }


        virtual void move(Character *enemy);
        virtual void slash(Character *enemy);
        string print() override;
         ~Ninja() override = default;
};