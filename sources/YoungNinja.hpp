#pragma once

#include "Character.hpp"

class YoungNinja: public Ninja{
    
    public:
     // constructors:
    YoungNinja( const char* name , Point location  );
     string print() override;
};