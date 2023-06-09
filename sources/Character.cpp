
#include "Character.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;
namespace ariel{}

Character::Character(const char* name , Point location , int hitPoints):
Name(name) , Location(location) , Hit_points(hitPoints) , type(0), inTeam(false){
    if (hitPoints<0){
        throw invalid_argument ("no character begin dead");
    }
}

Character::Character(): 
Name(NULL) , Location(Point()) , Hit_points(0), type(0){}


    // Copy assignment operator
    Character& Character ::operator=(const Character& other) {
        if (this != &other) {
            Name = other.Name;
            Hit_points = other.Hit_points;
            inTeam = other.inTeam;
            Location = other.Location;
            type = other.type;
        }
        return *this;
    }

    // Move assignment operator
    Character& Character ::operator=(Character&& other) noexcept {
        if (this != &other) {
            delete[] Name;
            Name = (other.Name);
            Hit_points = other.Hit_points;
            inTeam = other.inTeam;
            Location = (other.Location);
            type = other.type;

            other.Name = nullptr;
            other.Hit_points = 0;
            other.inTeam = false;
            other.type = 0;
        }
        return *this;
    }

const char* Character :: getName(){
    return this->Name;
}
Point Character::getLocation(){
    return this->Location;
}
int Character:: getHitPoints(){
    return this->Hit_points;
}
void Character ::setHitpoints(int number){
    this->Hit_points = number;
}
bool Character::isAlive(){
    return this->Hit_points>0;
}
double Character::distance(Character *other){
    return this->Location.distance(other->getLocation());
}
void Character::hit(int number){
    if (number <0)
        throw invalid_argument ("negative number"); 
    this->setHitpoints(this->getHitPoints() - number);
}

int Character::getType(){
    return this->type;
}

string Character :: print(){
    string print = "some character";
    return print;
} 

/************************************************************************************/

Ninja::Ninja(const char* name, Point location , int hitPoints, int speedtype): 
Character(name , location , hitPoints), speed(speedtype){
    this->type =2;
} 

Ninja::Ninja(){}

 void Ninja::move(Character *enemy){
    if (! this->isAlive() || !enemy->isAlive()){
    throw runtime_error ("Dead characters cannot move and characters cannot move to dead enemy");
   }
    if (enemy == this){
        throw runtime_error ("no need to move to myself");
    }

    this->Location = this->Location.moveTowards(this->getLocation() , enemy->getLocation() , this->speed);
}

 void Ninja::slash(Character *enemy){
    if (! this->isAlive() || !enemy->isAlive()){
    throw runtime_error ("Dead characters cannot attack and characters cannot attack a dead enemy");
   }

    if (enemy == this){
        throw runtime_error (" No self harm");
    }
    bool meter = this->distance(enemy) <= 1;

    if (this->isAlive() && meter && enemy !=this){
        enemy->hit(40);
    }

}
 
string Ninja::print() {
    std::ostringstream oss;
    oss << "N: ";
    float x = (this->getLocation().getX());
    float y = (this->getLocation().getY());
        if (!this->isAlive()){
        oss<<"( " <<this->getName()<<") ";
    }

    if(this->isAlive())
    {
    oss<<(this->getName()) << "with "<<(this->getHitPoints())<<" hit points.";
    }
    oss << " place in point: (" << std::fixed << std::setprecision(2) << x << "," << y << ")\n";
    return oss.str();
}
