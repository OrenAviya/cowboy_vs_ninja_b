#include "TrainedNinja.hpp"

TrainedNinja::TrainedNinja(const char* name , Point location  ): //speed =12
Ninja(name , location , 120 , 12){}

string TrainedNinja:: print(){
string res = Ninja:: print();
return res;
}