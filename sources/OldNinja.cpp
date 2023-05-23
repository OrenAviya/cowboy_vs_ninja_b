#include "Character.hpp"
#include "OldNinja.hpp"


/************************************************************************************/
OldNinja::OldNinja(const char* name, Point location)://speed = 8
Ninja(name , location , 150 , 8){}

string OldNinja:: print(){
string res = Ninja:: print();
return res;
}