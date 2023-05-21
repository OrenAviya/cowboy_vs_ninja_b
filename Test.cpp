#include "sources/Team.hpp"

#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include "doctest.h"

using namespace doctest;

TEST_CASE("check point class"){
    SUBCASE("check point creation"){
    Point p1(2,3);
    CHECK(p1.getX() == 2);
    CHECK(p1.getY() == 3);
}
    SUBCASE("check moveTowards method"){
        Point p1(1,1);
        Point p2(4,5);

    CHECK(p1.distance(p2) == 5.0);
    Point p3 = p1.moveTowards(p1, p2, 2);
    CHECK(p3.distance(p1) == 2.0);
    CHECK(p3.distance(p2) == 3.0);
    }
}

TEST_CASE("check Character-cowboy class"){
    Point point(0,0);
    Cowboy cowboy("motek" , point);
    CHECK(cowboy.getHitPoints() == 110);
    CHECK(cowboy.getLocation().getX() == point.getX());
    CHECK(cowboy.getLocation().getY() == point.getY());
    CHECK(cowboy.isAlive() == true);
}

TEST_CASE("check cowboy's methods"){
    Cowboy cowboy("motek" , Point(22,20));
    Character enemy("enemy" , Point(1,1) , 10);
    cowboy.shoot(&enemy);
    CHECK(cowboy.getNumBullet() == 5);
    CHECK(enemy.isAlive() == false);
    cowboy.reload();
    CHECK(cowboy.getNumBullet() == 6);
}

TEST_CASE("check Character-Ninja class"){
    Ninja nin("nini" , Point(3,3) , 120 , 14);
    CHECK(nin.getHitPoints() == 120);
    CHECK(nin.getName() == "nini");
    CHECK(nin.isAlive() == true);
    CHECK(nin.getLocation().getX() == 3);
    CHECK(nin.getLocation().getY() == 3);
  
}

TEST_CASE("check oldNinja"){
    OldNinja old("oldy" , Point(6,7));
    Character moveto("enemy" , Point(1,1) , 10);
    CHECK_NOTHROW(old.move(&moveto));

    CHECK(old.isAlive());
    CHECK(old.getHitPoints() == 150);

}

TEST_CASE("check youngNinja"){
    YoungNinja you("sary" , Point(2,3));
    Character moveto("enemy" , Point(1,1) , 10);
    CHECK_NOTHROW(you.move(&moveto));
    
CHECK(you.isAlive());
CHECK(you.getHitPoints() == 100);
}

TEST_CASE("check trainedNinja"){
 TrainedNinja  train("rati" , Point(9,50));
 Character moveto("enemy" , Point(1,1) , 10);
CHECK_NOTHROW(train.move(&moveto));

CHECK(train.isAlive());
CHECK(train.getHitPoints() == 120);

}

TEST_CASE("CHECK ninja methods"){
OldNinja old("oldi", Point(15, 0));
Character enemy("enemy" , Point( 15,1) , 40);
old.slash(&enemy);
CHECK(enemy.isAlive() == false);

YoungNinja you("nang", Point(0, 15));
Character enemy1("enemy" , Point( 0,1) , 40);
you.slash(&enemy1);
CHECK(enemy1.getHitPoints() == 40);
CHECK(enemy1.isAlive() == true);
}

TEST_CASE("check Team class "){
    OldNinja lead("leader" , Point(7,7));
    Team team(&lead);
    
    CHECK (team.getLeader() == &lead);
    
    CHECK(team.size == 1);
    CHECK(team.stillAlive() == 1);
}

TEST_CASE("check Team class - stillAlive method "){
    TrainedNinja lead("leader" , Point(7,7));
    Team team(&lead);
    Cowboy c1("boker", Point(5, 6));
    Cowboy c2("boker2", Point(7, 8));
    team.add(&c1);
    team.add(&c2);

    CHECK(team.size ==3);
    CHECK(team.stillAlive() ==3);

    for(int i=0 ; i<15 ; i++)
        c1.shoot(&c2);
    
    CHECK(c2.isAlive() == false);
    CHECK(team.size ==3);
    CHECK(team.stillAlive()==2);

}

TEST_CASE("check team attack "){
    Cowboy leader1("mike", Point(0, 1));
    Cowboy leader2("jodi" , Point(0 , 2));
    Team team1(&leader1);
    Team team2(&leader2);

    OldNinja w1("w1" , Point(0,0));
    TrainedNinja w2("w2" , Point(1,1));
    YoungNinja w3("w3" , Point(2,2));

    OldNinja w4("w4" , Point(3,3));
    TrainedNinja w6("w6" , Point(4,4));
    YoungNinja w5("w5" , Point(5,5));

    team1.add(&w1);
    team1.add(&w2);
    team1.add(&w3);

    team2.add(&w4);
    team2.add(&w5);
    team2.add(&w6);

    team1.attack(&team2);
    for (int i=0 ; i<5 ; i++)
        team2.attack(&team1);

    CHECK(team1.stillAlive() < 4);
    CHECK(team2.stillAlive() == 4);
}

TEST_CASE("check team dead leader "){
    Cowboy c1("lead" , Point(0,0));
    Team  t1(&c1);

    Team t2(new OldNinja("enemy" , Point(0,1)));
    t2.attack(&t1);
    CHECK(t1.stillAlive() ==1);
    CHECK(t1.getLeader()->isAlive() == true);
    for (int i=0 ; i<=6 ; i++){
        t2.attack(&t1);
    }

}
TEST_CASE("check Character distance"){
    Point p1(6, 7);
    Point p2(6,8);
    OldNinja o1("dor", p2);
    OldNinja o2("ron", p1);
        double dis = o1.distance(&o2);
        CHECK(dis == 1.0);
}

TEST_CASE("check point distance "){
    Point p(0,0);
    Point p1(0,1);

    CHECK (p.distance(p1) == 1.0);

}
TEST_CASE("check characters ") {
    Character chari("Char" , Point(0, 0), 50);
    Character char2("Char2" , Point(0, 0), 0);
    
    CHECK_THROWS(Character ("Char1" ,Point(0, 0), -10));
    CHECK(chari.isAlive() == true);
    CHECK(char2.isAlive() == false);
}

TEST_CASE("negative hit points") {
    Character chr("nik" ,Point(0, 0), 100);
    CHECK_THROWS(chr.hit(-1));
}

TEST_CASE("check hit method "){
     Cowboy c1("lead" , Point(0,0));
      OldNinja w1("w1" , Point(0,0));

      c1.hit(10);
      w1.hit(40);

      CHECK(c1.getHitPoints() == 100);
       CHECK(w1.getHitPoints() == 110);

}
TEST_CASE("check get type method"){
    Cowboy c1("lead" , Point(0,0));
    OldNinja w1("w1" , Point(0,0));

    CHECK (c1.getType() == 1);
    CHECK (w1.getType() == 2);

}
TEST_CASE("check getters "){
Cowboy c1("lead" , Point(0,0));
    

    CHECK_NOTHROW(c1.getHitPoints());
    
    CHECK_NOTHROW(c1.getLocation() );
    CHECK_NOTHROW(c1.getName());
    CHECK_NOTHROW(c1.getNumBullet()) ;
}

TEST_CASE("check getters"){
OldNinja w1("w1" , Point(0,0));
CHECK_NOTHROW(w1.getHitPoints());
CHECK_NOTHROW(w1.getLocation());
CHECK_NOTHROW(w1.getName());

}
TEST_CASE("check ClosestCharToLead "){
    Cowboy leader1("mike", Point(0, 1));    
    Team team1(&leader1);
    CHECK_NOTHROW(team1.ClosestCharToLead());

}

TEST_CASE("check ClosestCharToLead "){
    Cowboy leader1("mike", Point(0, 1));
    Cowboy leader2("jodi" , Point(0 , 2));
    Team team1(&leader1);
    Team team2(&leader2);

    CHECK_NOTHROW(team1.ClosestCharToLead(&team2));
}

TEST_CASE("check character try to hit itself"){
 Cowboy leader1("mike", Point(0, 1));
leader1.shoot(&leader1);
OldNinja leader2("jodi" , Point(0 , 2)); 
leader2.slash(&leader2);
// CHECK there is no hit :
CHECK(leader1.getHitPoints() == 110);
CHECK(leader2.getHitPoints() == 150);


}

TEST_CASE("check efficient of SmartTeam and team2 "){
    Cowboy leader1("lead1", Point(0, 1));
    Cowboy leader2("lead2" , Point(0 , 2));
    Cowboy leader3("lead3" , Point(0 , 2));
    OldNinja n1("n1" , Point(0,0));
    OldNinja n2("n2" , Point(0,0));
    OldNinja n7("n7" , Point(0,0));
    YoungNinja n3("n3", Point (20 ,20));
    YoungNinja n4("n4" , Point (0,30));
    YoungNinja n8("n8" , Point (0,30));
    TrainedNinja n5("n5" , Point (60 , 50));
    TrainedNinja n6 ("n6" , Point (22 , 90));
    TrainedNinja n9 ("n9" , Point (22 , 90));

    Team team(&leader1);
    SmartTeam smart(&leader2);
    Team2 team2(&leader3);
    
    team.add(&n1);
    team.add(&n5);
    team.add(&n3);

    smart.add(&n2);
    smart.add(&n6);
    smart.add(&n4);

    team2.add(&n7);
    team2.add(&n8);
    team2.add(&n9);

int counter=0;
    for( int i =0 ; i<10 ; i++){
       counter++;
      cout<<"in while\n";
        smart.attack(&team);
        cout <<"attack:" <<counter<<"\n";
        if (team.stillAlive()>0 && smart.stillAlive()>0 )
            team.attack(&smart);
        else
            break;
        cout <<"attack:" <<counter<<"\n";
    }
    for( int i =0 ; i<10 ; i++){
       counter++;
      cout<<"in while\n";
      if (team.stillAlive()>0 && team2.stillAlive()>0 ){
        team2.attack(&team);
        cout <<"attack:" <<counter<<"\n";
    }
        if (team.stillAlive()>0 && team2.stillAlive()>0 )
            team.attack(&team2);
        else
            break;
        cout <<"attack:" <<counter<<"\n";
    }

    CHECK(smart.stillAlive() > team.stillAlive());
    CHECK(team2.stillAlive() > team.stillAlive());


}
