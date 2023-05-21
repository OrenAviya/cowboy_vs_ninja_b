#pragma once
#include "Team.hpp"
#include "SmartTeam.hpp"

class SmartTeam : public Team {
//The transition to the characters will be according to your choice
public:
SmartTeam(Character *leader): Team(leader){}
void  add(Character* some) override;
void attack(Team *EnemyTeam) override;
Character* SmartChooseVictim(Team* EnemyTeam);
};

