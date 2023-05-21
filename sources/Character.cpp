
#include "Character.hpp"
#include <stdio.h>
#include <stdlib.h>


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

Character Character ::operator =(Character *some){
   Character c1 = Character(some->getName() , some->getLocation(), some->getHitPoints() );
    return c1;
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
 
string Ninja::print(){
    string print = string(this->getName()) + " ";
    if (!this->isAlive()){
        print+="is dead";
        return print;
    }

    if(this->isAlive())
    {
    print +="with "+ to_string(this->getHitPoints())+" hit points. place in point: ";
    print += " (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")\n";
    }

    return print;
}
