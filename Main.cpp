#include "doctest.h"
#include "sources/Leauge.hpp"
using namespace std;
using namespace ariel;
TEST_CASE("Teams tests"){
    vector<Team*> myTeam;
    CHECK_THROWS(myTeam.push_back(new Team("",0)));
    CHECK_THROWS(myTeam.push_back(new Team("\r",0)));
    CHECK_THROWS(myTeam.push_back(new Team("\n",0)));
    CHECK_THROWS(myTeam.push_back(new Team("\t",0)));
    CHECK_THROWS(myTeam.push_back(new Team("\r",0)));
    CHECK_THROWS(myTeam.push_back(new Team(" ",0)));
    CHECK_NOTHROW(myTeam.push_back(new Team("1",0)));
    CHECK_NOTHROW(myTeam.push_back(new Team("2",0.4)));
    CHECK_NOTHROW(myTeam.push_back(new Team("3",0.2)));
    CHECK_NOTHROW(myTeam.push_back(new Team("5",0.3)));
    CHECK_THROW(myTeam.push_back(new Team("4",-0.0456)));
    CHECK_NOTHROW(myTeam.push_back(new Team("6",1)));
    CHECK_NOTHROW(myTeam.push_back(new Team("7",0.98)));
    CHECK_NOTHROW(myTeam.push_back(new Team("8",0.65)));
    CHECK_NOTHROW(myTeam.push_back(new Team("9",0.21)));
    CHECK_NOTHROW(myTeam.push_back(new Team("10",0.56)));
    CHECK_THROWS(myTeam.push_back(new Team("11",-568)));
    CHECK_THROWS(myTeam.push_back(new Team("12",-1.547)));
    CHECK_THROWS()

}
TEST_CASE("Test Leauge"){
    vector<Team*> myTeams;
    myTeams.push_back(new Team("Golden State Warriors", 1));
    myTeams.push_back(new Team("Boston Celtics", 0.4));
    myTeams.push_back(new Team("Brooklyn Nets", 0.5));
    myTeams.push_back(new Team("Denver Nuggets", 0.3));
    myTeams.push_back(new Team("Philadelphia 76ers", 0.4));
    myTeams.push_back(new Team("Minnesota Timberwolves", 0.5));
    myTeams.push_back(new Team("Chicago Bulls", 0.3));
    myTeams.push_back(new Team("Portland Trail Blazers", 0.2));
    myTeams.push_back(new Team("LA Clippers", 0.5));
    myTeams.push_back(new Team("Los Angeles Lakers", 1));
    myTeams.push_back(new Team("Milwaukee Bucks", 0.7));
    myTeams.push_back(new Team("Atlanta Hawks", 0.3));
    myTeams.push_back(new Team("Charlotte Hornets", 0.2));
    myTeams.push_back(new Team("Miami Heat", 0.6));
    myTeams.push_back(new Team("Phoenix Suns", 0.8));
    myTeams.push_back(new Team("Dallas Mavericks", 0.6));
    myTeams.push_back(new Team("Memphis Grizzlies", 0.5));
    myTeams.push_back(new Team("Utah Jazz", 0.3));
    myTeams.push_back(new Team("Washington Wizards", 0));
    myTeams.push_back(new Team("Oklahoma City Thunder", 0.1));
    Leauge* l = new Leauge(myTeams);
    CHECK_THROWS(l->printLeauge(5));
    l->startLeauge();
    CHECK_NOTHROW(l->printLeauge(5));
}