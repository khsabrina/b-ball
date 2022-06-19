#ifndef EX6_GAME_H
#define EX6_GAME_H
#endif 
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Team.hpp"
#include <time.h>
#include <cstdlib> 

namespace ariel{
    class Game{
    public:
        Team* home;
        Team* away;
        Game(Team* a,Team* b):home(a),away(b){
            srand(time(0));
        }
        ~Game();

        int random_number(int num1, int num2);
        Team* start_game();
    };
}
