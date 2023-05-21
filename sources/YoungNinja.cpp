#include "Character.hpp"
#include "YoungNinja.hpp"

YoungNinja::YoungNinja(const char* name , Point location  )//speed=14
:Ninja(name , location , 100 , 14){}

string YoungNinja:: print(){
string res = "Type YoungNinja, ";
res += Ninja:: print();
return res;
}