#include "doctest.h"
#include "sources/Leauge.hpp"
using namespace std;
using namespace ariel;
TEST_CASE("Teams tests"){
    vector<Team*> myTeam;
    CHECK_THROWS(myTeam.push_back(new Team("1",6)));
    CHECK_THROWS(myTeam.push_back(new Team("1",7)));
    CHECK_THROWS(myTeam.push_back(new Team("1",8)));
    CHECK_THROWS(myTeam.push_back(new Team("1",9)));
    CHECK_NOTHROW(myTeam.push_back(new Team("1",0.76)));
    CHECK_NOTHROW(myTeam.push_back(new Team("2",0.4)));
    CHECK_NOTHROW(myTeam.push_back(new Team("3",0.2)));
    CHECK_NOTHROW(myTeam.push_back(new Team("5",0.3)));
    CHECK_THROWS(myTeam.push_back(new Team("4",-0.0456)));
    CHECK_NOTHROW(myTeam.push_back(new Team("6",1)));
    CHECK_NOTHROW(myTeam.push_back(new Team("7",0.98)));
    CHECK_NOTHROW(myTeam.push_back(new Team("8",0.65)));
    CHECK_NOTHROW(myTeam.push_back(new Team("9",0.21)));
    CHECK_NOTHROW(myTeam.push_back(new Team("10",0.56)));
    CHECK_THROWS(myTeam.push_back(new Team("11",-568)));
    CHECK_THROWS(myTeam.push_back(new Team("12",-1.547)));
    CHECK_NOTHROW(myTeam.push_back(new Team("4",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("11",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("12",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("13",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("14",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("15",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("16",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("17",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("18",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("19",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("20",0.3)));
    Leauge* new_game = new Leauge(myTeam);
    CHECK_THROWS(new_game->printLeauge(7));
    CHECK_THROWS(new_game->printLeauge(1));
    new_game->startLeauge();
    CHECK_NOTHROW(new_game->printLeauge(7));
     CHECK_NOTHROW(new_game->printLeauge(1));

}