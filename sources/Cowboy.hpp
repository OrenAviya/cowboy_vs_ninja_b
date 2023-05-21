#pragma once

#include "Character.hpp"

using namespace std;
namespace ariel{}

class Cowboy : public Character{
    public:
        int num_of_bullet;
              
    // constructors:
    Cowboy(const char* name, Point location  ); //always with 6 bullet and 011 hit points
    Cowboy(Cowboy&& other) noexcept;
    Cowboy(const Cowboy& other);

        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        Cowboy& operator =(Cowboy const &some);
        Cowboy& operator=(Cowboy&& other) noexcept;
        void setNumBullet(int number);
        int getNumBullet();
        string print() override;
        ~Cowboy() override= default;
    
};
