// CS1300 Fall 2020
// Author: Bryce Schumacher
// Recitation: 509 – Michael Hoefer
// Final Project

// Raider clss implementation (see if raid or not)
#include "Raid.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

    bool Raid::isRaid(double raidval) {
        srand(time(0)+283);
        int x = (rand() % 100) + 1;
        if (x < raidval) {
            return 1;
        }
        else {
            return 0;
        }
    }



