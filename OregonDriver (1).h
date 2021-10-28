#include "Mileage.cpp"
#include "Player.cpp"
#include "Utilities.cpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class Driver
{
private:

Player P;

Utilities U;

Mileage M;

bool quit;

public:

Driver();

void setDate(int, int, int);

void changeDate(int); // Sam

string getDate(); // Sam

bool checkDate();// Sam

void startGame(); //*

void shop();//* ?

void encounterFort();//*

void encounterRiver();//*

void turn(); //offers an option menu within a while loop and calls *

//void hunt();

void misfortune();

void sick(); //*

void brokenParts(); // *

void oxenDies(); // *

void raiderEncounter();

int endTurn(); //*

void winGame(); //*

bool checkGame(); //*

bool exitGame(); //*

};