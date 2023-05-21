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
constexpr int MaxWarriors = 10;

class Team{
// The transition to the characters will be according to cowboy first
   public:
    
    array<Character*, MaxWarriors> warriors;
    Character *leader;
    // (the same but not tameplate): Character warriors [10];
    
    size_t size;
    //constructor
Team(Character *leader);
    
// Copy constructor implementation
Team(const Team& other)
    : warriors(other.warriors), leader(other.leader), size(other.size) {
    
}

// Move constructor implementation
Team(Team&& other) noexcept
    : warriors((other.warriors)),
      leader((other.leader)),
      size((other.size)) {
    }

    //destructor
virtual ~Team()
    {
    for (size_t i = this->size ; i >0 ; i--){
        delete (warriors.at(i-1)) ;
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
        Character* getLeader() const {
            return this->leader;
        }
        Team& operator=(const Team& other);
        Team& operator=(Team&& other) noexcept;
};
