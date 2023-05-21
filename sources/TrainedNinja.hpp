#pragma once 

#include "Character.hpp"
#include "Point.hpp"

using namespace std;
namespace ariel{}

class TrainedNinja: public Ninja{
    
    public:
     // constructors:
    TrainedNinja(const char* name, Point location  );
     string print() override;

};