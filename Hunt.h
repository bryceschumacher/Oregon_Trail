// CS1300 Fall 2020
// Author: Bryce Schumacher
// Recitation: 509 – Michael Hoefer
// Final Project

#include <string>
using namespace std;

//Hunt class header file
class Hunt
{
    public:
    Hunt(double rabbit_prob, double fox_prob, double deer_prob, double bear_prob, double moose_prob);

    void setRabbitProb(double prob);

    void setFoxProb(double prob);

    void setDeerProb(double prob);

    void setBearProb(double prob);

    void setMooseProb(double prob);

    bool rabbitTurn();

    bool foxTurn();
    
    bool deerTurn();

    bool bearTurn();

    bool mooseTurn();


    private:
    double days_elapsed;
    double prob_of_rabbit;
    double prob_of_fox;
    double prob_of_deer;
    double prob_of_bear;
    double prob_of_moose;
};