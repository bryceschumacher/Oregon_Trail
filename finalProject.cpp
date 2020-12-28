// CS1300 Fall 2020
// Author: Bryce Schumacher
// Recitation: 509 – Michael Hoefer
// Final Project

#include <iostream>
using namespace std;
#include <string>
#include "Player.h"
#include "Shop.h"
#include "Hunt.h"
#include "Raid.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cmath>

//Hey! Welcome to my final project.. I pretty much just brute forced this to get it over with so I could study for other
//classes. If I were to do this project again, I would have made it much more efficient, but hey! It works.. Enjoy
// Run using g++ finalProject.cpp Player.cpp Shop.cpp Hunt.cpp Raid.cpp

//Four classes are Player, Shop, Raid, and Hunt

//Simple tolower function so I could include user input of words such as "yes" or "no" instead of just numbers
string toLower(string user_name) {
    	string user = "";
    int count = 0;
    char ch;
    while (user_name[count])
    {
        ch=user_name[count];
        user += char((tolower(ch)));
        count++;
    }
    return user;
}

//Function used when I want user to pause and read something in terminal before proceeding.
void spaceFunction() {
string val = "d";
while(val != "") {
        cout << "Press enter to continue" << endl;
        getline(cin, val);
        if(val == "") {
            continue;
        }
        else {
            cout << "Invalid input." << endl;
        }
    }
}


int main() {
    // Introduction to game
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Welcome to The Oregon Trail" << endl;
    cout << "Created by Bryce Schumacher" << endl;
    cout << "For Final Project CSCI 1300" << endl;
    cout << "(Based heavily on the popular game, The Oregon Trail)" << endl;
    spaceFunction();
    string names[5] = {};
    string option = "";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    //Getting player names
    cout << "What is the first name of the wagon leader?" << endl;
    getline(cin, names[0]);
    int i = 0;
    while(names[4] == "") {
    cout << "1. " << names[0] << endl;
    cout << "2. " << names[1] << endl;
    cout << "3. " << names[2] << endl;
    cout << "4. " << names[3] << endl;
    cout << "5. " << names[4] << endl;
    cout << "What are the first names of the four other members in your party?" << endl;
    i++;
    getline(cin, names[i]);
    }
    cout << "1. " << names[0] << endl;
    cout << "2. " << names[1] << endl;
    cout << "3. " << names[2] << endl;
    cout << "4. " << names[3] << endl;
    cout << "5. " << names[4] << endl;
    // Checking if names are correct
    while(toLower(option) != "yes") {
        cout << "Are these names correct?" << endl;
        getline(cin, option);
        if(toLower(option) == "yes") {
            continue;
        }
        else if(toLower(option) == "no") {
            cout << endl;
            cout << "Re-run program and enter names again." << endl;
            return 0;
        }
        else {
            cout << endl;
            cout << "Invalid input." << endl;
        }
    }
    Player player1 = Player(1600, names[0], names[1], names[2], names[3], names[4]);
    string option2;
    int option2int = 0;
    cout << endl;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    //This while seen below is checking whether user input is a digit. If so, it should proceed. If not, prompt user with
    // INVALID INPUT
    // Below this is initial date choosing
    while(isdigit(option2[0]) == false) {
    cout << "It is 1847. Your jumping off place for Oregon is Independence Missouri. You must decide when to leave Independence. You must reach Oregon City by November 30th." << endl;
    cout << "What is your choice? Leave On:" << endl << endl;
    cout << "1. March 28th" << endl;
    cout << "2. Choose your own date" << endl;
    cout << "3. Quit" << endl;
    getline(cin, option2);
        if(isdigit(option2[0])) {
        option2int = stoi(option2);
        }
        else {
            cout << endl << endl;
            cout << "INVALID INPUT" << endl;
            spaceFunction();
            cout << endl << endl;
        }
    }
    switch(option2int) {
        case 1 :
            {
                player1.setDaysElapsed(27);
                break;
            }
        case 2 :
            {
                string entered;
                int enteredint = -10;
                while(enteredint < 0 || enteredint > 34) {
                    cout << "Enter how many days after March 1st you're going to leave. The latest departure date is May 1st (61 days after March 1st)" << endl;
                    getline(cin, entered);
                    enteredint = stoi(entered);
                    if(enteredint >= 0 && enteredint <= 61) {
                        player1.setDaysElapsed(enteredint);
                        break;
                    }
                    else {
                        cout << "Invalid input." << endl;
                    }
                }
                break;
            }
        case 3 :
            {
                cout << "Goodbye!" << endl;
                return 0;
            }
        default :
            {
                cout << "Invalid input. Try again" << endl;
            }
    }
    cout << endl;
    cout << "Before leaving Independence, you should buy supplies. You have $1600 to spend but you don't have to spend it all now." << endl;
    cout << "You have the option of purchasing oxen, food, bullets, wagon parts, and first aid kits." << endl;
    spaceFunction();
    cout << endl;

    // This is my shop. Creates an object of class Shop with constructor being multiplier of shop prices
    // Then sets new Balance, and adds the items purchased to my player class' inventory
    Shop independence = Shop(1.00);
    int a = player1.getBalance();
    int b = player1.getOxenRemaining();
    int c = player1.getFood();
    int d = player1.getBulletsRemaining();
    int e = player1.getWagonPartsRemaining();
    int f = player1.getFirstAidKitsRemaining();
    vector<int> tempvec;
    tempvec = independence.shopShow(1.00, a, b, c, d, e, f);

    player1.setAllItems(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]);
    player1.setBalance(player1.getBalance()-independence.totalBill(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]));
    cout << "Total Balance remaining: " << player1.getBalance() << endl;
    spaceFunction();

    // At this point, the player is set up and ready to proceed. Next is my "turn" system.
    Hunt hunt1 = Hunt(0.5, 0.25, 0.15, 0.07, 0.05);
    Raid raid1;
    ifstream file;
    string line1;
    int line_counter = 0;
    int q = 0;
    int p = 0;
    string strone;
    string strtwo;
    string milestonenames[100] = {};
    int milestonedistances[100] = {};
    // Opens given milestone.txt and stores lines into milestonenames or milestonedistances respectively
    file.open("milestones.txt");
    while(getline(file,line1)) {
        stringstream nc(line1);
        if(line_counter % 2 == 0) {
            getline(nc, strone);
            milestonenames[p] = strone;
            p++;
        }
        else {
            getline(nc, strtwo, 'm');
            string str;
            for(int i = 0; i < strtwo.length(); i++) {
                if(isdigit(strtwo[i])) {
                    str += strtwo[i];
                }
            }
            milestonedistances[q] = stoi(str);
            q++;
        }
        line_counter++;
    }
    int counter = 0;
    int cnt = 18;
    // Turn system ahead: Stops functioning if any of below conditions are not met (out of food, wagon parts, etc.)
    while(player1.getFood() > 0 && player1.getOxenRemaining() > 0 && player1.getWagonPartsRemaining() > -1 && player1.isAlive() == true && player1.getDaysElapsed() < 276 && player1.getMilesTraveled() < 2040) {
        cout << "\n\n\n";
        player1.statusUpdate();
        spaceFunction();
        string optstring;
        int opt = 0;
        while(opt > 4 || opt < 1) {
            cout << "\n";
            cout << "What would you like to do?" << endl;
            cout << "1. Stop to rest" << endl;
            cout << "2. Continue on the trail." << endl;
            cout << "3. Hunt" << endl;
            cout << "4. Quit" << endl;
            getline(cin,optstring);
            opt = stoi(optstring);
            srand(time(0));
            switch(opt) {
                case 1:
                    {
                        //Resting option: Takes between 1 and 3 days to rest, achieved wih rand(). Sets food accordingly
                        int day = (rand() % 3) + 1;
                        cout << "\n";
                        cout << "You rested for " << day << " days." << endl;
                        cout << "You ate " << player1.countPlayersAlive()*day*3 << " lbs. of food." << endl;
                        player1.setDaysElapsed(player1.getDaysElapsed() + day);
                        player1.setFood(player1.getFood() - (player1.countPlayersAlive()*day*3));
                        spaceFunction();
                        break;
                    }
                case 2:
                    {   
                        //Continue option: Goes forward x miles between 70 and 140
                        //Subtracts food accordingly
                        cout << "You decided to continue on the trail." << endl;
                        cout << "You consumed " << player1.countPlayersAlive()*14*3 << " lbs. of food." << endl;
                        player1.setFood(player1.getFood() - (player1.countPlayersAlive()*14*3));
                        int randmiles = (rand() % 70) + 70;
                        string opt3str;
                        int opt3 = 0;
                        int opt4 = 0;
                        string opt4str;
                        if(player1.getMilesTraveled() + randmiles >= milestonedistances[counter]) {
                                while(opt3 < 1 || opt3 > 2) {
                                    // If you go past a milestone, then asks if you want to stop at that milestone or continue
                                    cout << "You were prepared to travel " << randmiles << " miles but you arrived at " << milestonenames[counter] << ". What do you want to do?" << endl;
                                    cout << "(1) Rest, (2) Continue" << endl;
                                    getline(cin,opt3str);
                                    opt3 = stoi(opt3str);
                                    switch(opt3) {
                                        case 1:
                                            {
                                                cout << "You decide to stop at " << milestonenames[counter] << endl;
                                                player1.setMilesTraveled(milestonedistances[counter]);
                                                //If milestone starts with letter F, then it is a fort. Offer to player if they want to shop
                                                if(milestonenames[counter][0] == 'F') {
                                                    if(counter == 2) {
                                                        Shop kearney = Shop(1+(0.25*(counter+1)));
                                                        a = player1.getBalance();
                                                        b = player1.getOxenRemaining();
                                                        c = player1.getFood();
                                                        d = player1.getBulletsRemaining();
                                                        e = player1.getWagonPartsRemaining();
                                                        f = player1.getFirstAidKitsRemaining();
                                                        vector<int> tempvec;
                                                        tempvec = kearney.shopShowTwo(1.25, a, b, c, d, e, f);

                                                        player1.setAllItems(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]);
                                                        player1.setBalance(player1.getBalance()-independence.totalBill(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]));
                                                        cout << "Total Balance remaining: " << player1.getBalance() << endl;
                                                        spaceFunction();
                                                    }
                                                    else if(counter == 4) {
                                                        Shop laramie = Shop(1+(0.25*(counter+1)));
                                                        a = player1.getBalance();
                                                        b = player1.getOxenRemaining();
                                                        c = player1.getFood();
                                                        d = player1.getBulletsRemaining();
                                                        e = player1.getWagonPartsRemaining();
                                                        f = player1.getFirstAidKitsRemaining();
                                                        vector<int> tempvec;
                                                        tempvec = laramie.shopShowTwo(1.5, a, b, c, d, e, f);

                                                        player1.setAllItems(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]);
                                                        player1.setBalance(player1.getBalance()-independence.totalBill(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]));
                                                        cout << "Total Balance remaining: " << player1.getBalance() << endl;
                                                        spaceFunction();
                                                    }
                                                    else if(counter == 7) {
                                                        Shop bridger = Shop(1+(0.25*(counter+1)));
                                                        a = player1.getBalance();
                                                        b = player1.getOxenRemaining();
                                                        c = player1.getFood();
                                                        d = player1.getBulletsRemaining();
                                                        e = player1.getWagonPartsRemaining();
                                                        f = player1.getFirstAidKitsRemaining();
                                                        vector<int> tempvec;
                                                        tempvec = bridger.shopShowTwo(1.75, a, b, c, d, e, f);

                                                        player1.setAllItems(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]);
                                                        player1.setBalance(player1.getBalance()-independence.totalBill(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]));
                                                        cout << "Total Balance remaining: " << player1.getBalance() << endl;
                                                        spaceFunction();
                                                    }
                                                    else if(counter == 10) {
                                                        Shop hall = Shop(1+(0.25*(counter+1)));
                                                        a = player1.getBalance();
                                                        b = player1.getOxenRemaining();
                                                        c = player1.getFood();
                                                        d = player1.getBulletsRemaining();
                                                        e = player1.getWagonPartsRemaining();
                                                        f = player1.getFirstAidKitsRemaining();
                                                        vector<int> tempvec;
                                                        tempvec = hall.shopShowTwo(2, a, b, c, d, e, f);

                                                        player1.setAllItems(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]);
                                                        player1.setBalance(player1.getBalance()-independence.totalBill(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]));
                                                        cout << "Total Balance remaining: " << player1.getBalance() << endl;
                                                        spaceFunction();
                                                    }
                                                    else if(counter == 12) {
                                                        Shop boise = Shop(1+(0.25*(counter+1)));
                                                        a = player1.getBalance();
                                                        b = player1.getOxenRemaining();
                                                        c = player1.getFood();
                                                        d = player1.getBulletsRemaining();
                                                        e = player1.getWagonPartsRemaining();
                                                        f = player1.getFirstAidKitsRemaining();
                                                        vector<int> tempvec;
                                                        tempvec = boise.shopShowTwo(2.25, a, b, c, d, e, f);

                                                        player1.setAllItems(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]);
                                                        player1.setBalance(player1.getBalance()-independence.totalBill(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]));
                                                        cout << "Total Balance remaining: " << player1.getBalance() << endl;
                                                        spaceFunction();
                                                    }
                                                    else if(counter == 14) {
                                                        Shop walla = Shop(1+(0.25*(counter+1)));
                                                        a = player1.getBalance();
                                                        b = player1.getOxenRemaining();
                                                        c = player1.getFood();
                                                        d = player1.getBulletsRemaining();
                                                        e = player1.getWagonPartsRemaining();
                                                        f = player1.getFirstAidKitsRemaining();
                                                        vector<int> tempvec;
                                                        tempvec = walla.shopShowTwo(2.5, a, b, c, d, e, f);

                                                        player1.setAllItems(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]);
                                                        player1.setBalance(player1.getBalance()-independence.totalBill(tempvec[0],tempvec[1],tempvec[2],tempvec[3],tempvec[4]));
                                                        cout << "Total Balance remaining: " << player1.getBalance() << endl;
                                                        spaceFunction();
                                                    }
                                                }
                                                counter++;
                                                break;
                                            }
                                        case 2:
                                            {
                                                cout << "You continue your journey." << endl;
                                                player1.setMilesTraveled(player1.getMilesTraveled() + randmiles);
                                                counter++;
                                                break;
                                            }
                                        default:
                                            {
                                                cout << "Invalid argument." << endl;
                                            }
                                    }
                                }
                            
                        }
                        else {
                            //If player doesn't go past a milestone
                            player1.setMilesTraveled(player1.getMilesTraveled() + randmiles);
                        }
                        player1.setDaysElapsed(player1.getDaysElapsed() + 14);
                        //This below is my setter for Miles til next milestone
                        for(int g = 0; g < 15; g++) {
                            if(player1.getMilesTraveled() < milestonedistances[g]) {
                                player1.setMilesTilMilestone(milestonedistances[g]-player1.getMilesTraveled());
                                break;
                            }
                        }
                        
                        break;
                    }
                case 3:
                    {
                        //Hunting option: There is a lot of code here and a lot of repitition. If I had more time, I would reduce this
                        // dramatically!
                        string inputrabbitstr;
                        string inputfoxstr;
                        string inputdeerstr;
                        string inputbearstr;
                        string inputmoosestr;
                        int inputrabbit = 0;
                        int inputfox = 0;
                        int inputdeer = 0;
                        int inputbear = 0;
                        int inputmoose = 0;
                        //Initial menu, uses hunting class to test probabilities of whether or not which animals appear (seen in Hunt.cpp)
                        cout << "You decided to hunt." << endl;
                        cout << "You hunted for one day." << endl;
                        player1.setDaysElapsed(player1.getDaysElapsed()+1);
                        if(hunt1.rabbitTurn() == true) {
                            cout << "You see a rabbit." << endl;
                            cout << "Do you want to hunt it?" << endl;
                            cout << "(1) YES, (2) NO" << endl;
                            getline(cin, inputrabbitstr);
                            inputrabbit = stoi(inputrabbitstr);
                            switch(inputrabbit) {
                                case 1:
                                    {
                                        //If hunt is successful or not
                                        if(player1.getBulletsRemaining()*20 < 10) {
                                            cout << "The hunt was unsuccessful." << endl;
                                        }
                                        else {
                                            string inpstr;
                                            int inp = 0;
                                            int count = 0;
                                            srand(time(0)+10);
                                            int y = (rand() % 10) + 1;
                                            while(count < 3) {
                                                //This is my puzzle right here
                                                cout << "Guess a number between 1 and 10." << endl;
                                                getline(cin, inpstr);
                                                inp = stoi(inpstr);
                                                if(y == inp) {
                                                    cout << "You solved the puzzle! You got 5 lbs. of food and lost 10 bullets." << endl;
                                                    player1.setBullets(player1.getBulletsRemaining() - 0.5);
                                                    player1.setFood(player1.getFood() + 5);
                                                    break;
                                                }
                                                else {
                                                    cout << "Darn! You didn't guess the right number." << endl;
                                                }
                                                count += 1;
                                            }
                                        }
                                    }
                                case 2:
                                    {
                                        cout << endl;
                                    }
                                default:
                                    {
                                        cout << "Invalid argument." << endl;
                                    }
                            }
                        }
                        //Repeats per animal.. i know a lot of code
                        if(hunt1.foxTurn() == true) {
                            cout << "You see a fox." << endl;
                            cout << "Do you want to hunt it?" << endl;
                            cout << "(1) YES, (2) NO" << endl;
                            getline(cin, inputfoxstr);
                            inputfox = stoi(inputfoxstr);
                            switch(inputfox) {
                                case 1:
                                    {
                                        if(player1.getBulletsRemaining()*20 < 10) {
                                            cout << "The hunt was unsuccessful." << endl;
                                        }
                                        else {
                                            string inpstr;
                                            int inp = 0;
                                            int count = 0;
                                            srand(time(0)+5);
                                            int y = (rand() % 10) + 1;
                                            while(count < 3) {
                                                cout << "Guess a number between 1 and 10." << endl;
                                                getline(cin, inpstr);
                                                inp = stoi(inpstr);
                                                if(y == inp) {
                                                    cout << "You solved the puzzle! You got 10 lbs. of food and lost 8 bullets." << endl;
                                                    player1.setBullets(player1.getBulletsRemaining() - 0.4);
                                                    player1.setFood(player1.getFood() + 10);
                                                    break;
                                                }
                                                else {
                                                    cout << "Darn! You didn't guess the right number." << endl;
                                                }
                                                count += 1;
                                            }
                                        }
                                    }
                                case 2:
                                    {
                                        cout << endl;
                                    }
                                default:
                                    {
                                        cout << "Invalid argument." << endl;
                                    }
                            }
                        }
                        if(hunt1.deerTurn() == true) {
                            cout << "You see a deer." << endl;
                            cout << "Do you want to hunt it?" << endl;
                            cout << "(1) YES, (2) NO" << endl;
                            getline(cin, inputdeerstr);
                            inputdeer = stoi(inputdeerstr);
                            switch(inputdeer) {
                                case 1:
                                    {
                                        if(player1.getBulletsRemaining()*20 < 10) {
                                            cout << "The hunt was unsuccessful." << endl;
                                        }
                                        else {
                                            string inpstr;
                                            int inp = 0;
                                            int count = 0;
                                            srand(time(0)+17);
                                            int y = (rand() % 10) + 1;
                                            while(count < 3) {
                                                cout << "Guess a number between 1 and 10." << endl;
                                                getline(cin, inpstr);
                                                inp = stoi(inpstr);
                                                if(y == inp) {
                                                    cout << "You solved the puzzle! You got 60 lbs. of food and lost 5 bullets." << endl;
                                                    player1.setBullets(player1.getBulletsRemaining() - 0.25);
                                                    player1.setFood(player1.getFood() + 60);
                                                    break;
                                                }
                                                else {
                                                    cout << "Darn! You didn't guess the right number." << endl;
                                                }
                                                count += 1;
                                            }
                                        }
                                    }
                                case 2:
                                    {
                                        cout << endl;
                                    }
                                default:
                                    {
                                        cout << "Invalid argument." << endl;
                                    }
                            }
                        }
                        if(hunt1.bearTurn() == true) {
                            cout << "You see a bear." << endl;
                            cout << "Do you want to hunt it?" << endl;
                            cout << "(1) YES, (2) NO" << endl;
                            getline(cin, inputbearstr);
                            inputbear = stoi(inputbearstr);
                            switch(inputbear) {
                                case 1:
                                    {
                                        if(player1.getBulletsRemaining()*20 < 10) {
                                            cout << "The hunt was unsuccessful." << endl;
                                        }
                                        else {
                                            string inpstr;
                                            int inp = 0;
                                            int count = 0;
                                            srand(time(0)+10);
                                            int y = (rand() % 10) + 1;
                                            cout << y << "h" << endl;
                                            while(count < 3) {
                                                cout << "Guess a number between 1 and 10." << endl;
                                                getline(cin, inpstr);
                                                inp = stoi(inpstr);
                                                if(y == inp) {
                                                    cout << "You solved the puzzle! You got 200 lbs. of food and lost 10 bullets." << endl;
                                                    player1.setBullets(player1.getBulletsRemaining() - 0.5);
                                                    player1.setFood(player1.getFood() + 200);
                                                    break;
                                                }
                                                else {
                                                    cout << "Darn! You didn't guess the right number." << endl;
                                                }
                                                count += 1;
                                            }
                                        }
                                    }
                                case 2:
                                    {
                                        cout << endl;
                                    }
                                default:
                                    {
                                        cout << "Invalid argument." << endl;
                                    }
                            }
                        }
                        if(hunt1.mooseTurn() == true) {
                            cout << "You see a moose." << endl;
                            cout << "Do you want to hunt it?" << endl;
                            cout << "(1) YES, (2) NO" << endl;
                            getline(cin, inputmoosestr);
                            inputmoose = stoi(inputmoosestr);
                            switch(inputmoose) {
                                case 1:
                                    {
                                        if(player1.getBulletsRemaining()*20 < 10) {
                                            cout << "The hunt was unsuccessful." << endl;
                                        }
                                        else {
                                            string inpstr;
                                            int inp = 0;
                                            int count = 0;
                                            srand(time(0)+10);
                                            int y = (rand() % 10) + 1;
                                            while(count < 3) {
                                                cout << "Guess a number between 1 and 10." << endl;
                                                getline(cin, inpstr);
                                                inp = stoi(inpstr);
                                                if(y == inp) {
                                                    cout << "You solved the puzzle! You got 500 lbs. of food and lost 12 bullets." << endl;
                                                    player1.setBullets(player1.getBulletsRemaining() - 0.6);
                                                    player1.setFood(player1.getFood() + 500);
                                                    break;
                                                }
                                                else {
                                                    cout << "Darn! You didn't guess the right number." << endl;
                                                }
                                                count += 1;
                                            }
                                        }
                                    }
                                case 2:
                                    {
                                        cout << endl;
                                    }
                                default:
                                    {
                                        cout << "Invalid argument." << endl;
                                    }
                            }
                        }
                        int ran = 0;
                        string ranstr;
                        //How would you like to eat? bit of code
                        while(ran > 3 || ran < 1) {
                            cout << "You finished your hunting day. How well would you like to eat?" << endl;
                            cout << "(1) Poorly, (2) Moderately, (3) Well" << endl;
                            getline(cin,ranstr);
                            ran = stoi(ranstr);
                            switch(ran) {
                                case 1:
                                    {
                                        cout << "You eat poorly." << endl;
                                        player1.setFood(player1.getFood()-(2*player1.countPlayersAlive()));
                                        break;
                                    }
                                case 2:
                                    {
                                        cout << "You eat moderately." << endl;
                                        player1.setFood(player1.getFood()-(3*player1.countPlayersAlive()));
                                        break;
                                    }
                                case 3:
                                    {
                                        cout << "You eat well." << endl;
                                        player1.setFood(player1.getFood()-(5*player1.countPlayersAlive()));
                                        break;
                                    }
                                default:
                                    {
                                        cout << "Invalid argument." << endl;
                                    }
                            }
                        }
                        //Can't hold more than 1000 lbs of food
                        if(player1.getFood() > 1000) {
                            cout << "The wagon cannot hold more than 1000 lbs. of food. The rest was left." << endl;
                            player1.setFood(1000);
                        }
                        

                        break;
                    }
                case 4:
                    {
                        cout << "Goodbye!" << endl;
                        return 0;
                    }
                default:
                    {
                        cout << "\n\n\n\n\n\n";
                        cout << "Invalid argument." << endl;
                    }
            }
        }
        // Misfortunes happen here because it's after their main turn
        srand(time(0)+(19*cnt));
        int x12 = (rand() % 10) + 1;
        if(x12 <= 4) {
            srand(time(0)+83*cnt);
            int x9 = (rand() % 3) + 1;
            switch(x9) {
                case 1:
                    {
                        //First misfortune: DISEASE
                        srand(time(0)+857);
                        int num = (rand() % 6) + 1;
                        //Assigns random disease
                        string disease;
                        string player;
                        switch(num) {
                            case 1:
                                {
                                    disease = "typhoid";
                                    break;
                                }
                            case 2:
                                {
                                    disease = "cholera";
                                    break;
                                }
                            case 3:
                                {
                                    disease = "diarrhea";
                                    break;
                                }
                            case 4:
                                {
                                    disease = "measles";
                                    break;
                                }
                            case 5:
                                {
                                    disease = "dysentery";
                                    break;
                                }
                            case 6:
                                {
                                    disease = "fever";
                                    break;
                                }
                            default:
                                {
                                    disease = "invalid";
                                    break;
                                }
                        }
                        srand(time(0)+95*cnt);
                        int num2 = (rand() % player1.countPlayersAlive()) + 1;
                        int numplayer;
                        //Assigns random player
                        switch(num2) {
                            case 1:
                                {
                                    player = names[0];
                                    numplayer = 0;
                                    break;
                                }
                            case 2:
                                {
                                    player = names[1];
                                    numplayer = 1;
                                    break;
                                }
                            case 3:
                                {
                                    player = names[2];
                                    numplayer = 2;
                                    break;
                                }
                            case 4:
                                {
                                    player = names[3];
                                    numplayer = 3;
                                    break;
                                }
                            case 5:
                                {
                                    player = names[4];
                                    numplayer = 4;
                                    break;
                                }
                        }
                        cout << "Oh no! " << player << " has " << disease << endl;
                        spaceFunction();
                        if(player1.getFirstAidKitsRemaining() > 0) {
                            player1.setFirstAidKits(player1.getFirstAidKitsRemaining()-1);
                            cout << "You had a medical kit!" << endl;
                            spaceFunction();
                            srand(time(0)+85*cnt);
                            int number3 = (rand() % 2) + 1;
                            if(number3 == 1) {
                                cout << player << " has recovered!" << endl;
                            }
                            else {
                                cout << player << " unfortunately still died." << endl;
                                int counter4 = 0;
                                names[numplayer] = "";
                            }
                        }
                        else {
                            string strd9;
                            int d9 = 0;
                            while(d9 < 1 || d9 > 2) {
                                cout << "You do not have a medical kit. You can either:" << endl;
                                cout << "(1) Rest, (2) Move on" << endl;
                                getline(cin,strd9);
                                d9 = stoi(strd9);
                                switch(d9) {
                                    case 1:
                                        {
                                            srand(time(0)+21*cnt);
                                            int d12 = (rand() % 10) + 1;
                                            cout << "You decide to rest." << endl;
                                            if(d12 <= 3) {
                                                cout << player << " has died." << endl;
                                                if (numplayer == 0) {
                                                    cout << "Game over." << endl;
                                                    player1.setFood(-1000);
                                                }
                                                int counter4 = 0;
                                                names[numplayer] = "";

                                            }
                                            else {
                                                cout << player << " has lived!" << endl;
                                            }
                                            break;
                                        }
                                    case 2:
                                        {
                                            srand(time(0)+83*cnt);
                                            int d12 = (rand() % 10) + 1;
                                            cout << "You decide to move on." << endl;
                                            if(d12 <= 7) {
                                                cout << player << " has died." << endl;
                                                int counter4 = 0;
                                                if (numplayer == 0) {
                                                    cout << "Game over." << endl;
                                                    player1.setFood(-1000);
                                                }
                                                names[numplayer] = "";

                                            }
                                            else {
                                                cout << player << " has lived!" << endl;
                                            }
                                            break;
                                        }
                                    default:
                                        {
                                            cout << "Invalid argument." << endl;
                                        }
                                }
                            }
                        }
                        break;
                    }
                case 2:
                    {
                        //Second misfortune: Oxen
                        cout << "Oh no! One of the Oxen has died! You have " << ((player1.getOxenRemaining()-0.5))*2 << " oxen left" << endl;
                        player1.setOxenRemaining(player1.getOxenRemaining()-0.5);
                        spaceFunction();
                        break;
                    }
                case 3:
                    {
                        //Third misfortune: Wagon part
                        if(player1.getWagonPartsRemaining() > 0) {
                            cout << "Oh no! One of your wagon parts broke. You have " << player1.getWagonPartsRemaining()-1 << " parts left." << endl;
                            player1.setWagonParts(player1.getWagonPartsRemaining() - 1);
                            spaceFunction();
                        }
                        else{
                            cout << "Oh no! One of your wagon parts broke." << endl;
                            player1.setFood(-1000);
                        }
                        break;
                    }
            }
        }
        cnt++;
        //This entire part is Raiders
        double milestravd = player1.getMilesTraveled();
        double numerator = pow((milestravd/100)-4,2)+72;
        double denom = pow((milestravd/100)-4,2)+12;
        double raidval = ((numerator/denom)-1)/0.1;
        if(raid1.isRaid(raidval) == true) {
            string option5str;
            int option5 = 0;
            while(option5 < 1 || option5 > 3) {
                //Menu
                cout << "Raiders Ahead! They look hostile!" << endl;
                cout << "You can either:" << endl;
                cout << "(1) Run, (2) Attack, (3) Surrender" << endl;
                getline(cin,option5str);
                option5 = stoi(option5str);
                switch(option5) {
                    case 1:
                        {
                            //Option 1: run
                            cout << "You escaped with your lives. Unfortunately, you left behind 1 ox, 10 lbs. of food, and 1 wagon part." << endl;
                            player1.setOxenRemaining(player1.getOxenRemaining()-0.5);
                            player1.setFood(player1.getFood()-10);
                            player1.setWagonParts(player1.getWagonPartsRemaining()-1);
                            break;
                        }
                    case 2:
                        {
                            //Option 2: Attack
                            cout << "In order to win, you must solve a puzzle." << endl;
                                string inpstr;
                                int inp = 0;
                                int win = 0;
                                int count = 0;
                                srand(time(0)+10);
                                int y = (rand() % 10) + 1;
                                while(count < 3) {
                                    cout << "Guess a number between 1 and 10." << endl;
                                    getline(cin, inpstr);
                                    inp = stoi(inpstr);
                                    if(y == inp) {
                                        cout << "You solved the puzzle! You got 50 lbs. of food and 50 bullets." << endl;
                                        player1.setBullets(player1.getBulletsRemaining() + 2.5);
                                        player1.setFood(player1.getFood() + 50);
                                        win += 1;
                                        break;
                                    }
                                    else {
                                        cout << "Darn! You didn't guess the right number." << endl;
                                    }
                                    count += 1;
                                }
                                if(win == 0) {
                                    cout << "You lost. You lose 1/4 of your cash and 50 bullets." << endl;
                                    player1.setBalance(player1.getBalance()-(player1.getBalance()/4.0));
                                    player1.setBullets(player1.getBulletsRemaining()-2.5);
                                }
                                break;
                        }
                    case 3:
                        {
                            //Option 3: Surrender
                            cout << "You surrender and lost 1/4 of your money." << endl;
                            player1.setBalance(player1.getBalance()-(player1.getBalance()/4.0));
                            break;
                        }
                    default:
                        {
                            cout << "Invalid argument." << endl;
                        }
                }
            }
        }

    }
    //When while loop above is exited out of for any reason, it checks the below conditions. If milestraveled >= 2040, they win.
    // If not, they lose. The results are written into a file "results.txt" 
    if(player1.getMilesTraveled() >= 2040) {
        cout << "Wow! You made it to Oregon." << endl;
        ofstream file1;
        file1.open ("results.txt");
        file1 << "You won!";
        file1.close();
    }
    else {
        if(player1.getWagonPartsRemaining() == 0) {
            cout << "You ran out of wagon parts." << endl;
            ofstream file1;
            file1.open ("results.txt");
            file1 << "You ran out of wagon parts.";
            file1.close();
        }
        else if(player1.getFood() <= 0) {
            cout << "You ran out of food." << endl;
            ofstream file1;
            file1.open ("results.txt");
            file1 << "You ran out of food.";
            file1.close();
        }
        else if(player1.isAlive() == 0) {
            cout << "You died." << endl;
            ofstream file1;
            file1.open ("results.txt");
            file1 << "Your main player died.";
            file1.close();
        }
        else if(player1.getOxenRemaining() == 0) {
            cout << "All your oxen died." << endl;
            ofstream file1;
            file1.open ("results.txt");
            file1 << "All your oxen died.";
            file1.close();
        }
        else if(player1.getDaysElapsed() >= 276) {
            cout << "You ran out of time." << endl;
            ofstream file1;
            file1.open ("results.txt");
            file1 << "You ran out of time.";
            file1.close();
        }
        cout << endl;
        cout << "_-Game Over-_" << endl;
        cout << endl;
    
    }

}
