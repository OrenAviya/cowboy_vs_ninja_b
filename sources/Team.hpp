#pragma once

#include "Character.hpp"
#include <stdio.h>
#include<stdlib.h>
#include "array"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

using namespace std;
namespace ariel{}

class Team{
// The transition to the characters will be according to cowboy first
   public:
    array <Character* , 10> warriors;
    
    Character *leader;
    // (the same but not tameplate): Character warriors [10];
    
    size_t size;
    //constructor
    Team(Character *leader);

    //destructor
~Team(){
    for (size_t i = this->size-1 ; i >=this->size ; i--){
        delete(warriors[i]) ;
    }
}
    //methods:
        virtual void add(Character *warr);
        virtual void attack(Team *anamyTeam);
        virtual int stillAlive();
       virtual void print();
        /// @brief method to find the closest character to the leader in the team
        /// @return pointer to that character
        virtual Character* ClosestCharToLead();
        /// @brief method to find the closest character to the leader of the team 
        // in the anamy team
        /// @param EnemyTeam 
        /// @return pointer to that character
        Character* ClosestCharToLead(Team* EnemyTeam);
        Character* getLeader(){
            return this->leader;
        }
};
