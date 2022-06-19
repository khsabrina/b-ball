#include "Game.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstdlib> 
using namespace std;
namespace ariel{

        Game::~Game(){}

        int Game::random_number(int num1, int num2){
            int random = (rand()%(num2-num1)) + num1;
            return random;
        }
        Team* Game::start_game(){
            int homeRand = random_number(55,100)+ (int)(this->home->talent * 10);
            int awayRand = random_number(50,100)+ (int)(this->away->talent * 10);
            this->home->add_points(homeRand, awayRand);
            this->away->add_points(awayRand,homeRand);
            if(homeRand>=awayRand){
                this->home->end_game_update(true);
                this->away->end_game_update(false);
                return this->home;
            }
            this->home->end_game_update(false);
            this->away->end_game_update(true);
            return this->away;
        }
}
