#ifndef EX6_TEAM_H
#define EX6_TEAM_H
#endif 
#pragma once
#include <iostream>
#include <string.h>
using namespace std;

namespace ariel{
    class Team{
    public:
        string name;
        double talent;
        int wins=0;
        int loses=0;
        int score_win=0;
        int score_lost=0;
        int wins_row_curr=0;
        int wins_row_max=0;
        int loses_row_curr=0;
        int loses_row_max=0;

        Team(string team_name,double team_talent);
        ~Team();

        void add_points(int score_win, int score_lost);
        void end_game_update(bool win);
        bool operator<(const Team& other) const;
    };
}
