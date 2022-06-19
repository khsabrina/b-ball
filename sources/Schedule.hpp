#ifndef EX5_PARTA_NODE_H
#define EX5_PARTA_NODE_H

#endif //EX5_PARTA_NODE_H
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
        ~Schedule(){}
        vector<Game*> makeSchedule (){
            vector<Game*> schedule;
            for (size_t i = 0; i < this->teams.size(); ++i) {
                for (size_t j = i; j < this->teams.size(); ++j) {
                    if(i!=j){
                        schedule.push_back(new Game(this->teams.at(i), this->teams.at(j)));
                        schedule.push_back(new Game(this->teams.at(j), this->teams.at(i)));
                    }
                }
            }
            return schedule;
        }
    };
}
