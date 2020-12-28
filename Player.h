// CS1300 Fall 2020
// Author: Bryce Schumacher
// Recitation: 509 – Michael Hoefer
// Final Project

#include <string>
using namespace std;

//Player class header file
class Player
{
    public:
    Player(double bal, string name_of_player1, string name_of_player2, string name_of_player3, string name_of_player4, string name_of_player5);

    double getFood();

    void setFood(double food_added);

    double getMilesTraveled();

    void setMilesTraveled(double miles);

    void statusUpdate();

    double getBalance();

    void setBalance(int new_balance);

    double getDaysElapsed();

    void setDaysElapsed(int days);

    double getBulletsRemaining();

    double getOxenRemaining();

    void setBullets(double bullets);

    double getWagonPartsRemaining();

    void setPlayerName(string name);

    string getPlayerName();

    void playerDead();

    bool isAlive();

    void setAllItems(double oxen, double food, double bullets, double wagon_parts, double aid);

    double getFirstAidKitsRemaining();

    void setFirstAidKits(double aid);

    void setOxenRemaining(double oxen);

    int countPlayersAlive();

    void setWagonParts(int wagon);

    string getDateFromDays(int days);

    void setMilesTilMilestone(double miles);

    double getMilesTilMilestone();

    private:

    double balance;
    double miles_traveled;
    double days_elapsed;
    double current_date;
    double distance_until_next_milestone;
    double food_available;
    double bullets_available;
    double num_of_days_in_rest;
    string player_name1;
    string player_name2;
    string player_name3;
    string player_name4;
    string player_name5;
    double miles_remaining;
    double oxen_available;
    double wagon_parts_available;
    bool is_alive;
    double first_aid_kits_available;
    double miles_til_milestone;
};