#include "Cowboy.hpp"
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace  std;

Cowboy::Cowboy(const char* name , Point location ):
Character(name , location, 110), num_of_bullet(6){
    this->type =1;
}

Cowboy::Cowboy(const Cowboy& other)
    : Character(other), num_of_bullet(other.num_of_bullet) {

}

// Move constructor implementation
Cowboy::Cowboy(Cowboy&& other) noexcept
    : Character(std::move(other)), num_of_bullet(other.num_of_bullet) {
   
}



int Cowboy:: getNumBullet(){
    return this->num_of_bullet;
}
void Cowboy::setNumBullet(int number){
    this->num_of_bullet = number;
}

void Cowboy::shoot(Character *enemy){
   if (!this->hasboolets()){
        cout<<"no bullets";
        this->reload();
        return;
   }

   if (! this->isAlive() || !enemy->isAlive()){
    throw runtime_error ("Dead characters cannot attack and characters cannot attack a dead enemy");
   }

    if (enemy == this){
        throw runtime_error (" No self harm");
    }

   if(enemy != this ){
    enemy->hit(10);
    this->num_of_bullet--;
   }

}
bool Cowboy::hasboolets(){
    return this->num_of_bullet>0;
}
void Cowboy::reload(){
    if (!this->isAlive()){
        throw runtime_error ("Dead cowboy can not reload");
    }
    this->num_of_bullet =6; 
}


Cowboy& Cowboy::operator=(const Cowboy& some) {
    if (this != &some) {
        Character::operator=(some);
        num_of_bullet = some.num_of_bullet;
    }
    return *this;
}


// Move assignment operator implementation
Cowboy& Cowboy::operator=(Cowboy&& other) noexcept {
    if (this != &other) {
        Character::operator=(std::move(other));
        num_of_bullet = other.num_of_bullet;
    }
    return *this;
}

string Cowboy::print() {
    std::ostringstream oss;
    oss << "C: ";
    float x = (this->getLocation().getX());
    float y = (this->getLocation().getY());
    
    if (isAlive()) {
        oss << getName() << " with " << getHitPoints() << " hit points. Place in point: ("
            << std::fixed << std::setprecision(2) << x << "," << y << ")\n";
    } else {
        oss << "(" << getName() << ") Place in point: ("
            << std::fixed << std::setprecision(2) << x << "," << y << ")\n";
    }

    return oss.str();
}
