
#include "Schedule.hpp"

using namespace std;
namespace ariel{
        Schedule::~Schedule(){}
        vector<Game*> Schedule::start_schedule (){
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
}
