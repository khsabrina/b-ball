#include <iostream>
#include <algorithm>
#include "Leauge.hpp"
int const NUMTEAMS = 20;
using namespace std;

namespace ariel{

    Leauge::Leauge(){
        this->active = false;
        for (int i = 0; i < NUMTEAMS; ++i) {
            this->teams.push_back(new Team(to_string(i),0.5));
        }
    }
    Leauge::Leauge(vector<Team*> teams){
        if (teams.size()>20){
            throw invalid_argument("We can get only 20 teams\n");
        }
        this->active = false;
        this->teams = teams;
        for(int i =teams.size(); i < NUMTEAMS; i++){
            this->teams.push_back(new Team(to_string(i),0.5));
        }
    }

    Leauge::~Leauge() {
        for (int i = (int)teams.size() - 1; i >= 0; --i) {
            delete teams.at((size_t)i);
        }
    }

    void Leauge::startLeauge(){
        Schedule* schedule = new Schedule(this->teams);
        vector<Game*> games = schedule->start_schedule();
        for (size_t i = 0; i < games.size(); ++i) {
            games.at(i)->start_game();
        }
        this->active = true;
        order_leauge();

    }

    void Leauge::order_leauge(){
        if (!this->active){
            throw invalid_argument("The leauge didn't started\n");
        }
        sort(this->teams.begin(), this->teams.end(),[](Team const * x, Team const * y){return *x < *y;});
    }
    void Leauge::printLeauge(int limit){
        if (!this->active){
            throw invalid_argument("The leauge didn't started\n");
        }
        cout << "The leading groups are:" << endl;
        for (size_t i = 0; i < limit; ++i) {
           cout << i+1 << ") " << this->teams[i]->name << "wins- loses" << this->teams[i]->wins << "/"<< this->teams[i]->loses<< endl;
        }
        Team* max_win = *max_element(this->teams.begin(), this->teams.end(),[](Team const * x, Team const * y){return x->wins_row_max < y->wins_row_max; });
        Team* max_lose = *min_element(this->teams.begin(), this->teams.end(),[](Team const * x, Team const * y){return x->loses_row_max > y->loses_row_max; });
        cout << "The team with the highest number of wins in a row " << max_win->name << " with: " << max_win->wins_row_max << " wins in a row!" << endl;
        cout << "The team with the highest number of loses in a row " << max_lose->name << " with: " << max_lose->loses_row_max << " loses in a row!" << endl;
        cout << "Teams that scored more than got scored:" << endl;
        for (size_t i = 0; i < NUMTEAMS; ++i) {
            if(this->teams[i]->score_win - this->teams[i]->score_lost > 0){
                cout << this->teams[i]->name <<endl;
            }
        }
    }

}