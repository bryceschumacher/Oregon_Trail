// CS1300 Fall 2020
// Author: Bryce Schumacher
// Recitation: 509 – Michael Hoefer
// Final Project

//Shop class header file
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Shop
{
    public:

    Shop(double multiplier);
    
    void shopUpdate(int a, int b, int c, int d, int e);

    double getPriceOfOxen();

    double getPriceOfFood();

    double getPriceOfBullets();

    double getPriceOfWagonParts();

    double getPriceOfFirstAid();
    
    double totalBill(int a, int b, int c, int d, int e);

    vector<int> shopShow(double multiplier, double currentbalance, int num_of_oxen, int num_of_food, int num_of_bullets, int num_of_parts, int num_of_kits);

    vector<int> shopShowTwo(double multiplier, double currentbalance, int num_of_oxen, int num_of_food, int num_of_bullets, int num_of_parts, int num_of_kits);
    


    private:
    double price_of_oxen;
    double price_of_food;
    double price_of_bullets;
    double price_of_wagon_part;
    double price_of_first_aid_kit;
    double new_price_of_oxen;
    double new_price_of_food;
    double new_price_of_bullets;
    double new_price_of_wagon_part;
    double new_price_of_first_aid_kit;
    double bill;
};

