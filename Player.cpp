// CS1300 Fall 2020
// Author: Bryce Schumacher
// Recitation: 509 – Michael Hoefer
// Final Project

//Implementation of Player class. Main class I used to assign dates, inventory, player stats, etc.
#include "Player.h"
#include <iostream>
using namespace std;
#include <string>
// Main constructor
    Player::Player(double bal, string name_of_player1, string name_of_player2, string name_of_player3, string name_of_player4, string name_of_player5) {
        balance = bal;
        miles_traveled = 0;
        days_elapsed = 0;
        current_date = 0;
        food_available = 0;
        bullets_available = 0;
        miles_remaining = 2040;
        miles_til_milestone = 102;
        player_name1 = name_of_player1;
        player_name2 = name_of_player2;
        player_name3 = name_of_player3;
        player_name4 = name_of_player4;
        player_name5 = name_of_player5;
        is_alive = true;

    }
    //Status update seen after each turn
    void Player::statusUpdate() {
        cout << "Current date: " << getDateFromDays(days_elapsed+1) << endl;
        cout << "Miles traveled: " << miles_traveled << endl;
        cout << "Next landmark in: " << miles_til_milestone << " miles" << endl;
        cout << "Food in lbs: " << food_available << endl;
        cout << "Number of bullets: " << 20*bullets_available << endl;
        cout << "Cash remaining: " << balance << endl;

    }
    // Member function transforms int days into a xx/yy/zz format
    string Player::getDateFromDays(int days) {
        string x;
        if(days < 32) {
            string str = to_string(days);
            x = "03/" + str + "/1847";
        }
        else if(days < 62) {
            string str = to_string(days-31);
            x = "04/" + str + "/1847";
        }
        else if(days < 92) {
            string str = to_string(days-61);
            x = "05/" + str + "/1847";
        }
        else if(days < 123) {
            string str = to_string(days-91);
            x = "06/" + str + "/1847";
        }
        else if(days < 154) {
            string str = to_string(days-122);
            x = "07/" + str + "/1847";
        }
        else if(days < 184) {
            string str = to_string(days-153);
            x = "08/" + str + "/1847";
        }
        else if(days < 215) {
            string str = to_string(days-183);
            x = "09/" + str + "/1847";
        }
        else if(days < 246) {
            string str = to_string(days-214);
            x = "10/" + str + "/1847";
        }
        else if(days < 276) {
            string str = to_string(days-275);
            x = "11/" + str + "/1847";
        }
        return x;
    }
    //Counts players currently alive
    int Player::countPlayersAlive() {
        int count = 0;
        if(player_name1 != "") {
            count += 1;
        }
        if(player_name2 != "") {
            count += 1;
        }
        if(player_name3 != "") {
            count += 1;
        }
        if(player_name4 != "") {
            count += 1;
        }
        if(player_name5 != "") {
            count += 1;
        }
        return count;
    }
    //Rest of member functions are pretty self explanatory
    void Player::playerDead() {
        is_alive = false;
    }

    void Player::setAllItems(double oxen, double food, double bullets, double wagon_parts, double aid) {
        oxen_available = oxen;
        food_available = food;
        bullets_available = bullets;
        wagon_parts_available = wagon_parts;
        first_aid_kits_available = aid;
    }

    double Player::getFirstAidKitsRemaining() {
        return first_aid_kits_available;
    }

    void Player::setFirstAidKits(double aid) {
        first_aid_kits_available = aid;
    }
    bool Player::isAlive() {
        return is_alive;
    }

    double Player::getFood() {
        return food_available;
    }

    void Player::setFood(double new_food) {
        food_available = new_food;
    }

    double Player::getMilesTraveled() {
        return miles_traveled;
    }

    void Player::setMilesTilMilestone(double miles) {
        miles_til_milestone = miles;
    }
    void Player::setMilesTraveled(double miles) {
        miles_traveled = miles;
    }

    double Player::getMilesTilMilestone() {
        return miles_til_milestone;
    }

    double Player::getBalance() {
        return balance;
    }

    double Player::getOxenRemaining() {
        return oxen_available;
    }

    void Player::setOxenRemaining(double oxen) {
        oxen_available = oxen;
    }

    double Player::getWagonPartsRemaining() {
        return wagon_parts_available;
    }

    void Player::setWagonParts(int wagon) {
        wagon_parts_available = wagon;
    }

    void Player::setBalance(int new_balance) {
        balance = new_balance;
    }

    double Player::getDaysElapsed() {
        return days_elapsed;
    }

    void Player::setDaysElapsed(int days) {
        days_elapsed = days;
    }

    double Player::getBulletsRemaining() {
        return bullets_available;
    }

    void Player::setBullets(double bullets) {
        bullets_available = bullets;
    }

    void Player::setPlayerName(string name) {
        player_name1 = name;
    }

    string Player::getPlayerName() {
        return player_name1;
    }