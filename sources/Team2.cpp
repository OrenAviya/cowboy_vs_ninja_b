   
   #include "Team2.hpp"
   #include "Character.hpp"
   #include "Cowboy.hpp"
   #include "OldNinja.hpp"
   #include "TrainedNinja.hpp"
   #include "YoungNinja.hpp"

   void Team2 :: print(){
    for (size_t i =0 ; i < this->size ; i++){
        cout << warriors.at(i)->print() << " , ";
    }
    cout<<"\n";
    }
    
    void Team2::add(Character* some){//regular add
        if (!some)
            return;
        if (some->inTeam)
            throw std::runtime_error("this warrior in other team");
    
        if (size < 10)
        {
            warriors[size] = some;
            size++;
        }
        else
        {
            throw runtime_error ("this team already have ten warriors");
        }
}


    Character* Team2::ClosestCharToLead(Team* EnemyTeam) {
        // Implementation of the ClosestCharToLead function
    return Team::ClosestCharToLead(EnemyTeam);
    }
    
    void Team2::attack(Team *enemyTeam) {
    if(enemyTeam == nullptr)
        throw std::invalid_argument("null input");
        
    if(this->stillAlive() == 0)
        throw std::invalid_argument("cannot attack if there is no player alive");
    
    if(enemyTeam->stillAlive() == 0)
        throw std::runtime_error("enemy team already dead");
    
    if(enemyTeam == this)
        throw std::invalid_argument("sory , Team would not attack itself");
    
    if ( ! this->leader->isAlive()){
        // new leader:
        this->leader = Team::ClosestCharToLead();
        }
    
    Character *victim = ClosestCharToLead(enemyTeam);
    for (size_t i=0; i<this->size; i++){
        if(victim == nullptr){
            return;
        }

        if(enemyTeam->stillAlive() == 0)
            return;

        if (warriors.at(i)->getType() == 1){
            Cowboy* co = static_cast<Cowboy*>(warriors.at(i));
            if (co->isAlive() && co->getNumBullet()>0){
                co->shoot(victim);
            }
            else if(co->isAlive() && co->getNumBullet() == 0){
                co->reload();
            }
        }
        else if (warriors.at(i)->getType() == 2){
            Ninja* nin  = static_cast<Ninja*>(warriors.at(i));
            if (nin->isAlive() && nin->distance(victim)<1){
                nin->slash(victim);
            }
            else if(nin->isAlive() && nin->distance(victim)>1){
                nin->move(victim);
            }
        }
        if (victim->isAlive() == false){
            victim = ClosestCharToLead(enemyTeam);
        }
    }
    
    }