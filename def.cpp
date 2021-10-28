#include <iostream>
#include <cmath>
#include"header.h"
#include "Utilities.h"
#include "Player.h"
using namespace std;

int randomNumbers(int min, int max){
    return (rand() % (max-min+1)) + min;
}

bool random(double percent)
{
    percent = percent * 100;
    int num = randomNumbers(1, 100);
    if(num <= percent)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool puzzle()
{
    
    int guess;
    int num = randomNumbers(1, 10);
    cout << "You must pass this puzzle to continue. Guess a number between 1 and 10 you have 3 trys." << endl;

    for(int i = 0; i < 3; i++)
    {
        cout << "Enter you first number" << endl;
        cin >> guess;
        if(guess == num)
        {
            cout << "You guessed corectly." << endl;
            return true;
        }
        else
        {
            cout << "Incorect guuess." << endl;
        }
        
    }
    return false;
}

raider::raider()
{
    is_attack = false;
}

bool raider::getraider(int mileage)
{
    double probabilty;

    probabilty = (((pow(((mileage/100)-4), 2) + 72) / (pow(((mileage/100)-4), 2) + 12)) - 1) / 10;

    bool result = random(probabilty);

    if(result == true)
    {
        cout << "RIDERS AHEAD! THEY LOOK HOSTILE!" << endl;
        is_attack = true;
    }
    else
    {
        is_attack = false;
    }
}

void raider::run()
{
    //call nescecary methods to minus 1 ox, 10lbs of fod, 1 wagon part
    U.changeMyOxen(-1);
    U.changeMyFood(-10);
    U.changeMyParts(-1);
}
void raider::attack()
{
    bool puzzle_result = puzzle();
    if(puzzle_result == true)
    {
        U.changeMyFood(50);
        U.changeMyBullets(50);
    }
    else
    {
        //minus .25 cash 50 bullets
        U.changeMyCash(U.getMyCash() * .75);
        U.changeMyBullets(-50);
    }
     
}
void raider::surrender()
{
    //minus quarter cash
    U.changeMyCash(U.getMyCash() * .75);
}



time_1::time_1()
{
    date[0] = 3;
    date[1] = 28;
    date[2] = 1847;
}

void time_1::get_date()
{
    cout << "The current date is: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
    return;
}
bool time_1::over_time()
{
    if(date[0] >= 11 && date[1] >= 30)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void time_1::set_date(int month, int day, int year)
{
    date[0] = month;
    date[1] = day;
    date[2] = year;
    return;
}
void time_1::add_days(int days)
{
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int remainder;

    if(days + date[1] <= daysInMonth[date[0]-1])
    {
        date[1] = date[1] + days;
    }
    else
    {
        remainder = (days + date[1]) - daysInMonth[date[0]-1];
        date[0]++;
        date[1]= 0;
        date[1] = remainder;
    }
    return;
    

}



void get_misfortune()
{
        int choice = randomNumbers(1,3);
        if(choice == 1)
        {
            int user = randomNumbers(0,4);
            
            string user_name = people[user];
            string sickness[6] = {"TYPHOID!","CHOLERA!","DIARRHEA!","MEASLES!","DYSENTERY!","FEVER!"};
            cout << "OH NO!"<< <<"HAS THE" << sickness[randomNumbers(0,5)] << endl;
            if(U.getMyMedkit() >= 1)
            {
                
            }
        }
        if(choice == 2)
        {
            U.changeMyOxen(-1);
            cout << "OH NO! ONE OF THE OXEN HAS DIED! YOU HAVE " << U.getMyOxen() << "OXEN LEFT." << endl;
        }
        if(choice == 3)
        {
            cout << "OH NO! YOUR WAGON IS BROKEN!" << endl;
            
            if(U.getMyParts() >= 1)
            {
                cout << "A part will be used to repair your wagon." << endl;
                U.changeMyParts(-1);
            }
            else
            {
                cout << "You have no more parts to repair your wagon." << endl;
                P.changeMeAlive();
            }
            
        }
}


void hunt()
{
    //add 1 day

    int num = randomNumbers(1,100);
    int choice;
    if(num <= 5)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A MOOSE! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
        cin >> choice;

        if(choice == 1)
        {
            if(getMyBullets() >= 10)
            {
                
            }
        }
    }
}