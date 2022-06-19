
#include "Team.hpp"
using namespace std;

namespace ariel{
        Team::Team(string team_name,double team_talent){
            if (team_talent<0 || team_talent>1){
                throw invalid_argument("Invalid talent\n");
            }
            this->name = team_name;
            this->talent = team_talent;
        }
        Team::~Team(){}

        void Team::add_points(int score_win, int score_lost){
            this->score_win += score_win; 
            this->score_lost += score_lost;
        }
        void Team::end_game_update(bool win){
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
        bool Team::operator<(const Team& other) const {
            if((this->wins - this->loses) == (other.wins- other.loses)){
                return (this->score_win - this->score_lost) > (other.score_win - other.score_lost);
            }
            return (this->wins- this->loses) > (other.wins- other.loses);
        }
}
