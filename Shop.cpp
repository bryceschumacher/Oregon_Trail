// CS1300 Fall 2020
// Author: Bryce Schumacher
// Recitation: 509 – Michael Hoefer
// Final Project

//Implementation of Shop class, functions pretty self explanatory
#include "Shop.h"
#include <iostream>
using namespace std;
#include <vector>

    Shop::Shop(double multiplier) {
        price_of_oxen = multiplier*40;
        price_of_food = multiplier*0.5;
        price_of_bullets = multiplier*2;
        price_of_wagon_part = multiplier*20;
        price_of_first_aid_kit = multiplier*25;
    }

    void Shop::shopUpdate(int a, int b, int c, int d, int e) {
        cout << "1. Oxen:           $" << price_of_oxen*a << " (" << a << " yoke)" << endl;
        cout << "2. Food:           $" << price_of_food*b << " (" << b << " lbs.)" << endl;
        cout << "3. Bullets:        $" << price_of_bullets*c << " (" << c << " boxes)" << endl;
        cout << "4. Wagon Parts:    $" << price_of_wagon_part*d << " (" << d << " part(s))" << endl;
        cout << "5. First Aid Kits: $" << price_of_first_aid_kit*e << " (" << e << " kits)" << endl;
        cout << "6. Quit            " << endl << endl;
        cout << "Total Bill:        $" << price_of_oxen*a + price_of_food*b + price_of_bullets * c + price_of_wagon_part * d + price_of_first_aid_kit*e << endl;

    }

    vector<int> Shop::shopShow(double multiplier, double currentbalance, int num_of_oxen, int num_of_food, int num_of_bullets, int num_of_parts, int num_of_kits) {
        Shop shopinstance = Shop(multiplier);
        string xstr;
        int x = 0;
        int a = num_of_oxen;
        int b = num_of_food;
        int c = num_of_bullets;
        int d = num_of_parts;
        int e = num_of_kits;
        int a1 = 0;
        int b1 = 0;
        int c1 = 0;
        int d1 = 0;
        int e1 = 0;
        while(x != 6 || a == 0 || b == 0) {
            cout << endl;
            cout << "\n\n";
            shopinstance.shopUpdate(a1,b1,c1,d1,e1);
            cout << "Current Balance:   $" << currentbalance << endl;
            cout << endl;
            //
            cout << "Which item would you like to buy? (6 to Quit) " << endl;
            cout << "Minimum Requirements: 200 lbs of food per person, 3 yoke of oxen" << endl;
            getline(cin,xstr);
            x = stoi(xstr);
            switch(x) {
                case 1:
                    {   
                        string z = "0";
                        while(stoi(z) < 3 || stoi(z) > 5) {
                            cout << "There are 2 oxen in a yoke and the price of each yoke is $" << multiplier*40 << ". You must purchase between 3 and 5 yokes of oxen. How many yoke would you like to buy?" << endl;
                            getline(cin, z);
                            if(stoi(z) >= 3 && stoi(z) <= 5) {
                                if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 40) <= 1600) {
                                    a += stoi(z);
                                    a1 += stoi(z);
                                }
                                else {
                                    cout << endl;
                                    cout << "You cannot purchase that many yoke." << endl;
                                }
                            }
                            else {
                                cout << "You must purchase between 3 and 5 yoke" << endl;
                            }
                        }
                        break;
                    }
                case 2:
                    {
                        string z = "0";
                        while(stoi(z) < 200) {
                            cout << "Each pound of food is $"<< multiplier*0.50 << ". You must purchase at least 200 lbs. of food per person. How many lbs would you like to buy?" << endl;
                            getline(cin, z);
                            if (stoi(z) >= 1000) {
                                if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 0.5) <= 1600) {
                                    b += stoi(z);
                                    b1 += stoi(z);
                                }
                                else {
                                    cout << endl;
                                    cout << "You cannot purchase that much food." << endl;
                                }
                            }
                            else {
                                cout << "You must purchase at least 200 lbs. of food per person" << endl;
                            }
                        }
                        break;
                    }
                case 3:
                    {
                        string z = "0";
                        cout << "A box of bullets costs $" << 2*multiplier << ". How many would you like to buy?" << endl;
                        getline(cin,z);
                        if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 2) <= 1600) {
                                c += stoi(z);
                                c1 += stoi(z);
                            }
                        else {
                            cout << endl;
                            cout << "You cannot purchase that many bullets." << endl;
                        }
                        break;
                    }
                case 4:
                    {
                        string z = "0";
                        cout << "A wagon part costs $" << 20*multiplier << ". How many would you like to buy?" << endl;
                        getline(cin,z);
                        if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 20) <= 1600) {
                            d += stoi(z);
                            d1 += stoi(z);
                        }
                        else {
                            cout << endl;
                            cout << "You cannot purchase that many parts." << endl;
                        }
                        break;
                    }
                case 5:
                    {
                        string z = "0";
                        cout << "A first aid kit costs $" << 25*multiplier << ". How many would you like to buy?" << endl;
                        getline(cin,z);
                        if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 25) <= 1600) {
                            e += stoi(z);
                            e1 += stoi(z);
                        }
                        else {
                            cout << endl;
                            cout << "You cannot purchase that many kits." << endl;
                        }
                        break;
                    }
                case 6:
                    {   
                        cout << endl;
                        if(a > 0 && b > 0 && d > 0) {
                            cout << "Goodbye!" << endl;
                        }
                        break;
                    }
                default:
                    {
                        cout << "Invalid input." << endl;
                        break;
                    }
            }
        }
        vector<int> y;
        y.push_back(a);
        y.push_back(b);
        y.push_back(c);
        y.push_back(d);
        y.push_back(e);
        return y;
    }
    vector<int> Shop::shopShowTwo(double multiplier, double currentbalance, int num_of_oxen, int num_of_food, int num_of_bullets, int num_of_parts, int num_of_kits) {
        Shop shopinstance = Shop(multiplier);
        string xstr;
        int x = 0;
        int a = num_of_oxen;
        int b = num_of_food;
        int c = num_of_bullets;
        int d = num_of_parts;
        int e = num_of_kits;
        int a1 = 0;
        int b1 = 0;
        int c1 = 0;
        int d1 = 0;
        int e1 = 0;
        while(x != 6) {
            cout << endl;
            shopinstance.shopUpdate(a1,b1,c1,d1,e1);
            cout << "Current Balance:   $" << currentbalance << endl;
            cout << endl;
            //
            cout << "Which item would you like to buy? (6 to Quit) " << endl;
            getline(cin,xstr);
            x = stoi(xstr);
            switch(x) {
                case 1:
                    {   
                        string z = "0";
                        while(stoi(z) < 3 || stoi(z) > 5) {
                            cout << "There are 2 oxen in a yoke and the price of each yoke is $" << multiplier*40 << ". You must purchase between 3 and 5 yokes of oxen. How many yoke would you like to buy?" << endl;
                            getline(cin, z);
                            if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 40) <= currentbalance) {
                                a += stoi(z);
                                a1 += stoi(z);
                            }
                            else {
                                cout << endl;
                                cout << "You cannot purchase that many yoke." << endl;
                            }
                            
                        }
                        break;
                    }
                case 2:
                    {
                        string z = "0";
                        while(stoi(z) < 200) {
                            cout << "Each pound of food is $"<< multiplier*0.50 << ". How many lbs would you like to buy?" << endl;
                            getline(cin, z);
                            if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 0.5) <= currentbalance) {
                                b += stoi(z);
                                b1 += stoi(z);
                            }
                            else {
                                cout << endl;
                                cout << "You cannot purchase that much food." << endl;
                            }
                            }
                        
                        break;
                    }
                case 3:
                    {
                        string z = "0";
                        cout << "A box of bullets costs $" << 2*multiplier << ". How many would you like to buy?" << endl;
                        getline(cin,z);
                        if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 2) <= currentbalance) {
                                c += stoi(z);
                                c1 += stoi(z);
                            }
                        else {
                            cout << endl;
                            cout << "You cannot purchase that many bullets." << endl;
                        }
                        break;
                    }
                case 4:
                    {
                        string z = "0";
                        cout << "A wagon part costs $" << 20*multiplier << ". How many would you like to buy?" << endl;
                        getline(cin,z);
                        if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 20) <= currentbalance) {
                            d += stoi(z);
                            d1 += stoi(z);
                        }
                        else {
                            cout << endl;
                            cout << "You cannot purchase that many parts." << endl;
                        }
                        break;
                    }
                case 5:
                    {
                        string z = "0";
                        cout << "A first aid kit costs $" << 25*multiplier << ". How many would you like to buy?" << endl;
                        getline(cin,z);
                        if(shopinstance.totalBill(a,b,c,d,e) + (stoi(z) * 25) <= currentbalance) {
                            e += stoi(z);
                            e1 += stoi(z);
                        }
                        else {
                            cout << endl;
                            cout << "You cannot purchase that many kits." << endl;
                        }
                        break;
                    }
                case 6:
                    {   
                        cout << endl;
                        if(a > 0 && b > 0 && d > 0) {
                            cout << "Goodbye!" << endl;
                        }
                        break;
                    }
                default:
                    {
                        cout << "Invalid input." << endl;
                    }
            }
        }
        vector<int> y;
        y.push_back(a);
        y.push_back(b);
        y.push_back(c);
        y.push_back(d);
        y.push_back(e);
        return y;
    }
    double Shop::totalBill(int a, int b, int c, int d, int e) {
        return price_of_oxen*a + price_of_food*b + price_of_bullets * c + price_of_wagon_part * d + price_of_first_aid_kit*e;
    }

    double Shop::getPriceOfOxen() {
        return price_of_oxen;
    }

    double Shop::getPriceOfFood() {
        return price_of_food;
    }

    double Shop::getPriceOfBullets() {
        return price_of_bullets;
    }

    double Shop::getPriceOfWagonParts() {
        return price_of_wagon_part;
    }

    double Shop::getPriceOfFirstAid() {
        return price_of_first_aid_kit;
    }