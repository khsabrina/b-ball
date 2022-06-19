#include <iostream>
#include <algorithm>
#include "Leauge.hpp"
int const MAXTEAMS = 20;
double const EPS = 0.0001;
using namespace std;

namespace ariel{

    Leauge::Leauge(){
        this->leaugeEnd = false;
        for (int i = 0; i < MAXTEAMS; ++i) {
            this->teams.push_back(new Team(to_string(i),0.5));
        }
    }
    Leauge::Leauge(vector<Team*> teams){
        if (teams.size()>20){
            throw invalid_argument("Too much teams\n");
        }
        this->leaugeEnd = false;
        this->teams = teams;
        for(int i =teams.size(); i < MAXTEAMS; i++){
            this->teams.push_back(new Team(to_string(i),0.5));
        }
    }

    Leauge::~Leauge() {
        for (int i = (int)teams.size() - 1; i >= 0; --i) {
            delete teams.at((size_t)i);
        }
    }

    void Leauge::startLeauge(){
        Schedule* sch = new Schedule(this->teams);
        vector<Game*> games = sch->makeSchedule();
        for (size_t i = 0; i < games.size(); ++i) {
            games.at(i)->startGame();
        }
        this->leaugeEnd = true;
        fixLeauge();

    }

    void Leauge::fixLeauge(){
        if (!this->leaugeEnd){
            throw invalid_argument("Cant do leauge functions as long as leauge didnt start\n");
        }
        sort(this->teams.begin(), this->teams.end(),[](Team const * x, Team const * y){return *x < *y;});
    }
    void Leauge::printLeauge(int limit){
        if (!this->leaugeEnd){
            throw invalid_argument("Cant do leauge functions as long as leauge didnt start\n");
        }
        cout << "Leauge Ranking" << endl;
        cout << "The leading groups are:" << endl;
        for (size_t i = 0; i < limit; ++i) {
           cout << i+1 << ") " << this->teams[i]->name << "wins- loses" << this->teams[i]->wins << "/"<< this->teams[i]->loses<< endl;
        }
        Team* max_win = *max_element(this->teams.begin(), this->teams.end(),[](Team const * x, Team const * y){return x->wins_row_max < y->wins_row_max; });
        Team* max_lose = *min_element(this->teams.begin(), this->teams.end(),[](Team const * x, Team const * y){return x->loses_row_max > y->loses_row_max; });
        std::cout << "The team with the highest number of wins in a row " << max_win->name << " with: " << max_win->wins_row_max << " wins in a row!" << std::endl;
        std::cout << "The team with the highest number of loses in a row " << max_lose->name << " with: " << max_lose->loses_row_max << " loses in a row!" << std::endl;
        std::cout << "Teams that scored more than they suffered:" << std::endl;
        for (size_t i = 0; i < MAXTEAMS; ++i) {
            if(this->teams[i]->score_win - this->teams[i]->score_lost > 0){
                std::cout << this->teams[i]->name << " with: " <<this->teams.at(i)->score_win << ":" <<this->teams.at(i)->score_lost << endl;
            }
        }
    }

}