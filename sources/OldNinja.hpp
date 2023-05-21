#pragma once
#include "Character.hpp"

using namespace std;


class OldNinja: public Ninja{
  
    public:
     // constructors:
    OldNinja(const char* name , Point location  );
    string print() override;
};

