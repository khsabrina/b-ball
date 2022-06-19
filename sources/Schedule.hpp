#ifndef EX6_SCHEDULE_H
#define EX6_SCHEDULE_H
#endif 
#pragma once
#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"

using namespace std;
namespace ariel{
    class Schedule{
    public:
        vector<Team*> teams;
        Schedule(vector<Team*> gameSet):teams(gameSet){}
        ~Schedule();
        vector<Game*> start_schedule ();
    };
}
