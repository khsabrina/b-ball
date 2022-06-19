#ifndef EX5A_ITERATOR_H
#define EX5A_ITERATOR_H

#endif //EX5A_ITERATOR_H
#pragma once
#include <iostream>
#include <string.h>
using namespace std;

namespace ariel{
    class Team{
    public:
        std::string name;
        double talent;
        int wins;
        int loses;
        int wins_row_curr;
        int wins_row_max;
        int loses_row_curr;
        int loses_row_max;
        double score;
        int score_win;
        int score_lost;

        Team(string teamName,double teamTalent){
            if (teamName == "\t" || teamName == "\n" || teamName.empty() || teamName == " " || teamName == "\r"){
                throw invalid_argument("Invalid team name\n");
            }
            if (teamTalent<0 || teamTalent>1){
                throw invalid_argument("Invalid talent range(Must be in range of [0,1])\n");
            }
            this->name = teamName;
            this->talent = teamTalent;
            this->wins_row_max = 0;
            this->wins_row_curr = 0;
            this->loses_row_curr = 0;
            this->loses_row_max = 0;
            this->wins = 0;
            this->loses = 0;
            this->score_win = 0;
            this->score_lost = 0;
        }
        ~Team(){}

        void add_points(int score_win, int score_lost){
            this->score_win += score_win; 
            this->score_lost += score_lost;
        }
        void end_game_update(bool win){
            if(win){
                this->loses_row_curr = 0;
                this->wins_row_curr+=1;
                this->wins+=1;
                this->wins_row_max = (this->wins_row_curr > this->wins_row_max)?this->wins_row_curr:this->wins_row_max;
            }
            else{
                this->wins_row_curr = 0;
                this->loses_row_curr+=1;
                this->loses+=1;
                this->loses_row_max = (this->loses_row_curr > this->loses_row_max)?this->loses_row_curr: this->loses_row_max;
            }
        }
        bool operator==(const Team& other) const {
            return name == other.name;
        }
        bool operator!=(const Team& other) const {
            return name != other.name;
        }
        bool operator<(const Team& other) const {
            if((this->wins - this->loses) == (other.wins- other.loses)){
                return (this->score_win - this->score_lost) > (other.score_win - other.score_lost);
            }
            return (this->wins- this->loses) > (other.wins- other.loses);
        }
    };
}
