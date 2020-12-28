// CS1300 Fall 2020
// Author: Bryce Schumacher
// Recitation: 509 – Michael Hoefer
// Final Project


#include "Hunt.h"
#include <cstdlib>
#include <ctime>

// Hunt class implementation. Probabilities of each animal calculates
    Hunt::Hunt(double rabbit_prob, double fox_prob, double deer_prob, double bear_prob, double moose_prob) {
        prob_of_rabbit = rabbit_prob;
        prob_of_fox = fox_prob;
        prob_of_deer = deer_prob;
        prob_of_bear = bear_prob;
        prob_of_moose = moose_prob;
    }

    bool Hunt::rabbitTurn() {
        int x = 0;
        srand(time(0));
        x = (rand() % 100) + 1;
        if(x <= prob_of_rabbit*100) {
            return true;
        }
        else {
            return false;
        }
    }
    bool Hunt::foxTurn() {
        int x = 0;
        srand(time(0)+1);
        x = (rand() % 100) + 1;
        if(x <= prob_of_fox*100) {
            return true;
        }
        else {
            return false;
        }
    }
    bool Hunt::deerTurn() {
        int x = 0;
        srand(time(0)+2);
        x = (rand() % 100) + 1;
        if(x <= prob_of_deer*100) {
            return true;
        }
        else {
            return false;
        }
    }
    bool Hunt::bearTurn() {
        int x = 0;
        srand(time(0)+3);
        x = (rand() % 100) + 1;
        if(x <= prob_of_bear*100) {
            return true;
        }
        else {
            return false;
        }
    }
    bool Hunt::mooseTurn() {
        int x = 0;
        srand(time(0)+4);
        x = (rand() % 100) + 1;
        if(x <= prob_of_moose*100) {
            return true;
        }
        else {
            return false;
        }
    }



    void Hunt::setRabbitProb(double prob) {
        prob_of_rabbit = prob;
    }

    void Hunt::setFoxProb(double prob) {
        prob_of_fox = prob;
    }

    void Hunt::setDeerProb(double prob) {
        prob_of_deer = prob;
    }

    void Hunt::setBearProb(double prob) {
        prob_of_bear = prob;
    }

    void Hunt::setMooseProb(double prob) {
        prob_of_moose = prob;
    }
