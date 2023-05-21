#include "SmartTeam.hpp"
#include <limits>

using namespace std;

void SmartTeam::attack(Team *EnemyTeam) {
        /*Implementation of the attack function:
        I will try to choose the victim such that 
        As many iive's ninjas from the attack team close to him 1 meter or less*/ 
    if(EnemyTeam == nullptr)
        throw std::invalid_argument("null input");
        
    if(this->stillAlive() == 0)
        throw std::invalid_argument("cannot attack if there is no player alive");
    
    if(EnemyTeam->stillAlive() == 0)
        throw std::runtime_error("enemy team already dead");
    
    if(EnemyTeam == this)
        throw std::invalid_argument("sory , Team would not attack itself");
    
    if ( ! this->leader->isAlive()){
        // new leader:
        this->leader = ClosestCharToLead();
        }

        Character* victim = SmartChooseVictim(EnemyTeam);
        for (size_t i=0; i<this->size; i++){
        
        if(victim == nullptr){
            return;
        }
        

        if(EnemyTeam->stillAlive() == 0)
            return;

        if (warriors[i]->getType() == 1){
            Cowboy* co = static_cast<Cowboy*>(warriors[i]);
            if (co->isAlive() && co->getNumBullet()>0){
                co->shoot(victim);
            }
            else if(co->isAlive() && co->getNumBullet() == 0){
                co->reload();
            }
        }
        else if (warriors[i]->getType() == 2){
            Ninja* nin  = static_cast<Ninja*>(warriors[i]);
            if (nin->isAlive() && nin->distance(victim)<1){
                nin->slash(victim);
            }
            else if(nin->isAlive() && nin->distance(victim)>1){
                /*If the victim is a ninja and "nin" may be the next victim
                So let him move to a point far away from the other ninjas,
                 let him approach some cowboy*/
                if(victim->getType() ==2 && EnemyTeam->ClosestCharToLead(this) == nin){
                    for(size_t i = EnemyTeam->size-1 ; i>=0 ; i--){
                        if (EnemyTeam->warriors[i]->getType()==1 && EnemyTeam->warriors[i]->isAlive() && EnemyTeam->warriors[i]->distance(nin)>1)
                            nin->move(EnemyTeam->warriors[i]);
                    }
                }
                else{
                    nin->move(victim);
                    }
            }
        }
        if (victim->isAlive() == false){
            victim = SmartChooseVictim(EnemyTeam);
        }
    }
    
    }
void SmartTeam:: add(Character* some){
        if (!some)
            return;
        
        if (size < 10)
        {
            warriors[size] = some;
            size++;
        }
        else
        {
            cout <<  "this team already have ten warriors";
        }
    }

    Character* SmartTeam:: SmartChooseVictim(Team* EnemyTeam){
        // chose the victim that in alive and at most live's ninjas is close to him. 
        int counter=0;
        int max_counter=0;
        size_t idx_victim = std::numeric_limits<size_t>::min();

        for (size_t i=0 ; i<EnemyTeam->size ; i++){
            Character* temp = EnemyTeam->warriors[i];
            if (temp->isAlive()){
                for (size_t j=0; j<size; j++) {
                    if (warriors[j]->isAlive() && warriors[j]->getType() == 2 && warriors[j]->distance(temp)<=1)
                        {
                            counter++;
                        }
                }   
            }
            if (counter > max_counter){
                max_counter = counter;
                idx_victim = i;
            }
        }
        if (idx_victim == std::numeric_limits<size_t>::min()){
            return ClosestCharToLead(EnemyTeam);
        }
        return EnemyTeam->warriors[idx_victim];
    }