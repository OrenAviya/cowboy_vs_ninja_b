#include "Cowboy.hpp"


Cowboy::Cowboy(const char* name , Point location ):
Character(name , location, 110), num_of_bullet(6){
    this->type =1;
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


Cowboy Cowboy ::operator =(Cowboy *some){
   Cowboy c1 = Cowboy(some->getName() , some->getLocation() );
   c1.setHitpoints(some->getHitPoints());
   c1.setNumBullet(some->getNumBullet());
    return c1;
}

string Cowboy:: print(){
string res = "cowboy " + string(getName()) + " with "+to_string(getHitPoints())+" hit points. place in point: "
+" (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")\n";
return res;
}
