#ifndef EX6_LEAUGE_H
#define EX6_LEAUGE_H
#endif 
#pragma once
#include <iostream>
#include <vector>
#include "Schedule.hpp"
#include "Team.hpp"
#include "Game.hpp"

using namespace std;


namespace ariel {

    class Leauge {
    public:
        vector<Team*> teams;
        bool active;
        Leauge();
        Leauge(vector<Team*> teams);
        ~Leauge();
        void startLeauge();
        void order_leauge();

        void printLeauge(int limit);
    };
}