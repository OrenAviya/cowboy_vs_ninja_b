#pragma once

#include "Character.hpp"

using namespace std;
namespace ariel{}

class Cowboy : public Character{
    private:
        int num_of_bullet;
        
            public:
    // constructors:
    Cowboy(const char* name, Point location  ); //always with 6 bullet and 011 hit points
       
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
Cowboy operator =(Cowboy *some);
void setNumBullet(int number);
int getNumBullet();
virtual string print();
// virtual ~Cowboy() = default;
    
};
