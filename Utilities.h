#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;


class Utilities
{
private:
double priceParts;
double priceBullets;
double priceFood;// per lb
double priceYolk; //2 oxen
double priceMedkit;
double percent; //starts at 1.00 and raises by .25 everytime riadePrices is called
double arrShopPrices[5]; //array of prices
string arrShopItems[5];

int myParts;
int myBullets;
double myCash;
int myFood;
int myOxen;
int myMedkit;

public:

Utilities();//sets the initial price of every utility 
//getPrice functions output the price of the parts
double getPriceParts();
double getPriceBullets();
double getPriceFood();// per lb
double getPriceYolk();//2 oxen
double getPriceMedkit();

void raisePrices();//raise all the prices by current prices every time this function is called it takes percentage and adds by .25
    
int getMyParts(); //outputs current number of parts
    
int getMyBullets(); //outputs current number of Bullets
    
int getMyCash(); //outputs current number of Cash
    
int getMyFood(); //outputs current number of Food
    
int getMyOxen(); //outputs current number of Oxen
    
int getMyMedkit(); //outputs current number of Medkits
    
    
//for all of changeMy fucntions take the current amount of utilities and add or subtract the int to the existing value and set the new value equal to myUtility
    
void changeMyParts(int);

void changeMyBullets(int);

void changeMyCash(int);//input a negative numver to lower cash! 

void changeMyFood(int);

void changeMyOxen(int);

void changeMyMedkit(int);

void shop();

    
};
