#pragma once 
#include "Team.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"

class Team2 : public Team {
public:
    Team2(Character *leader) : Team(leader) {}
    void  add(Character* some);
    void print() ;
    Character* ClosestCharToLead(Team* EnemyTeam) ;
    void attack(Team *EnemyTeam) ;
};
