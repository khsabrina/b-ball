#ifndef EX5A_ITERATOR_H
#define EX5A_ITERATOR_H

#endif //EX5A_ITERATOR_H
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Team.hpp"

namespace ariel{
    class Game{
    public:
        Team* home;
        Team* away;

        Game(Team* a,Team* b):home(a),away(b){}
        ~Game(){}

        int randNum(int A, int B){
            int r = (rand()%(B-A)) + A;
            return r;
        }

        Team* startGame(){
            int homeRand = randNum(55,100)+ (int)(this->home->talent * 10);
            int awayRand = randNum(50,100)+ (int)(this->away->talent * 10);
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
    };
}
