#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include "OregonDriver.h"
using namespace std;

int randomNumbers(int min, int max)
{
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

void get_misfortune()
{
        int choice = randomNumbers(1,3);
        if(choice == 1)
        {
            int user = randomNumbers(0,4);
            string user_name = people[user];

            string sickness[6] = {"TYPHOID!","CHOLERA!","DIARRHEA!","MEASLES!","DYSENTERY!","FEVER!"};

            cout << "OH NO!"<< user_name << "HAS THE" << sickness[randomNumbers(0,5)] << endl;
            
            if(U.getMyMedkit() >= 1)
            {
                cout << "Your medical kit was used." << endl;
                bool died = random(.5);

                if(died == true)
                {
                    cout << user_name << " has died despite using the medical kit." << endl;
                    P.peopleDied(user);
                }
                else
                {
                    cout << user_name << " lived." << endl;
                }
            }
            else
            {
                int option;
                cout << "You do not have a medical kit, would you like to (1): rest, (2): press on" << endl;
                cin >> option;

                if(option == 1)
                {
                    cout << "You rested for three days." << endl;
                    P.add_days(3);

                }
                else
                {
                    cout << "You pressed on." << endl;
                    bool chance = random(.7);
                    if(chance == true)
                    {
                        P.peopleDied(user);
                    }
                }
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Driver::Driver()
{
    P = Player();
    U = Utilities();
    M = Mileage();
    
    quit = false;
    
}

void Driver::startGame()
{
string player;
string passenger1;
string passenger2;
string passenger3;
string passenger4;

cout << "Welcome to Oregon Trail!" << endl << "Please enter your name" << endl;
cin >> player;
cout << "Please enter your first passengers name" << endl;
cin >> passenger1;
cout << "Please enter your second passengers name" << endl;
cin >> passenger2;
cout << "Please enter your third passengers name" << endl;
cin >> passenger3;
cout << "Please enter your fourth passengers name" << endl;
cin >> passenger4;

P.setPlayer(player, passenger1, passenger2, passenger3, passenger4);

cout << "Narrator: YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND SOME YOUR MONEY ON THE FOLLOWING ITEMS:" << endl << " -OXEN - YOU MUST SPEND $100-$200 ON YOUR TEAM. THESE CAN DIE ON THE JOURNEY SO PREPARE YOUR TEAM WELL" << endl;
cout << " -FOOD - THE MORE YOU HAVE, THE FURTHER YOU CAN TRAVEL" << endl;
cout << " -AMMUNITION - YOU WILL NEED BULLETS FOR HUNTING FOOD AND FOR KEEPING THOSE RAIDERS AWAY" << endl;
cout << " -MISCELLANEOUS SUPPLIES - THIS INCLUDES MEDKITS AND SPARE PARTS IF YOUR WAGON BREAKS DOWN" << endl << "SPEND YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. REMEMBER YOU MAY NEED SPARE CASH ALONG THE WAY, YOU NEVER KNOW WHAT YOU WILL RUN INTO ON THE TRAIL." << endl;
cout << " HOWEVER, ITEMS COST MORE AT THE FORTS" << endl;
cout << "YOU ARE AR THE SHOP WHAT WOULD YOU LIKE TO PURCHASE? REMEMBER PRICES GET HIGHER THE FURTHER YOU PROGRESS!" << endl;

return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Driver::turn()
{
    int option;
    int foodAte;
    int days;
    cout << "It is your turn. What would you like to do?" << endl;
    
    while (option != 2 || option != 5)
    {
        cout << "1. Rest" << endl << "2. Continue" << endl << "3. Hunt" << endl << "4. View Progress" << "5. Quit Game" << endl << "Please choose your option: ";
        cin >> option;
        
            if(option == 1) // rest
            {
                days = randomNumbers(0, 3);
                foodAte = days * P.getNumAlive() * 3;//amount of food ate during days
                U.changeMyFood(-foodAte);
                cout << "you rested for " << days << " days and consumed " << foodAte << "lbs of food. You have " << U.getMyFood() << "lbs remaining" <<  endl;
                D.changeDate(days);//change the date
                days = 0;
                foodAte = 0;
            }
            
            if(option == 2) //continue
            {
                cout << "Continue on the trail!" << endl;
            }
            if(option == 3) //hunt
            {
              hunt();
            }
            if(option == 4) //view progress
            {
                cout << "You have traveled " << M.getTotalMileage() << "mi and are " << M.nextFort() << "mi till the next fort and " << M.nextRiver() << "mi till the next river." << endl;
                cout << "Cash remaining: " << U.getMyCash() << endl;
                cout << "Food remaining: " << U.getMyFood() << endl;
                cout << "Oxen remaining: " << U.getMyOxen() << endl;
                cout << "Bullets remaining: " << U.getMyBullets() << endl;
                cout << "Spare parts remaining: " << U.getMyParts() << endl;
                cout << "Medkits remaining: " << U.getMyMedkit() << endl;
                
            }
            if(option == 5)
            {
               quit = true; 
            }
            else
            {
                cout << "Invalid option! Please chose one of the folling options:" << endl;
            }
    }
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Driver::shop()
{
   int option;
   int amount;
   bool first = false;
   bool first1 = false;
   int YN;

   while(option != 6)
   {
       YN = 0; //reset YN
       amount = 0;//reset amount
       
        cout << "options include" << endl;
        cout << "1. Buy Yolk (1 Yolk = 2 Oxen) a yolk costs" << U.getPriceYolk()  << endl;
        cout << "2. Buy Food, this costs" << U.getPriceFood() << "per pount (lb)" << endl;
        cout << "3. A box of 20 bullets this costs" << U.getPriceBullets() << endl;
        cout << "4. Wagon Parts (wheels, axles, tongues) this costs" << U.getPriceParts() << endl;
        cout << "5. Medical Kit this costs" << U.getPriceMedkit() << endl;
        cout << "6. Leave shop" << endl;
        cout << "Please input a number for the desired option" << endl;
        cin >> option;
        
        switch (option)
        {
           
            case 1: // Buy Yolk
            cout << "how many Yolk would you like to buy?" << endl;
            
                if (first == false) //first time in shop
                {
                cout << "you must buy $100-$200 worth of oxen to continue" << endl;
                
                while (U.getMyOxen() > 2 && U.getMyOxen() <= 5 )
                    {
                    U.changeMyOxen(0); 
                    cout << "how many Yolk would you like to buy?" << endl;
                    cin >> amount;
                    U.changeMyOxen(amount * 2);
                    }
                    U.changeMyCash(amount * U.getPriceYolk() * -1); //changes amount of cash you have remaining
                    first = true;
                    amount = 0;
                    break;
                }
                
            cin >> amount;  
            while (YN != 3) //asks user if they are satisfied with amount
            {
                cout << "Would you like to buy" << amount << "Yolks? Input 1 for YES, 2 for I want a different amount, or 3 to buy something else" << endl;
                cin >> YN;
                
                if(YN == 2)
                {
                    cout << "How many Yolk would you like to buy?" << endl;
                    cin >> amount;
                }
                
                if(YN == 1 && U.getMyCash() >= amount * U.getPriceYolk()) //you have enough money
                {
                  U.changeMyCash(amount * U.getPriceYolk() * -1); //change your money
                  
                  U.changeMyOxen((amount * 2));
                  
                  cout << "You have" << U.getMyCash() << "cash remaining and" << U.getMyOxen() << "oxen" << endl;
                  break;
                }
                
                if(YN == 1 && U.getMyCash() < amount * U.getPriceYolk()) //not enough money
                {
                    cout << "You don't have enough money" << endl;
                    cout << "How many Yolk would you like to buy?" << endl;
                    cin >> amount;
                }
            }
                break; // exit menu
                
                
                case 2: // buy food
                cout << "How many lbs of food would you like to buy? Each lb costs" << U.getPriceFood() << "cash." << endl;
                    if(first1 == false)//first time buying food
                    {
                        cout << "The store owner recommends the player(s) should purchase at least 200 lbs. of food per person, at 50 cents per pound." << endl;
                        first = true;
                    }
                cin >> amount; 
                
                    while (YN != 3) //asks user if they are satisfied with amount
                    {
                        cout << "Would you like to buy" << amount << "lbs of food? input 1 for YES, 2 for I want a different amount, or 3 to buy something else" << endl;
                        cin >> YN;
                
                        if(YN == 2)
                        {
                            cout << "How many lbs of food would you like to buy?" << endl;
                            cin >> amount;
                        }
                
                        if(YN == 1 && U.getMyCash() >= amount * U.getPriceFood()) //you have enough money
                        {
                            U.changeMyCash(amount * U.getPriceFood() * -1); //change your money
                            U.changeMyFood(amount);
                            cout << "You have" << U.getMyCash() << "cash remaining and" << U.getMyFood() << "lbs of food"; 
                            break;
                        }
                
                        if(YN == 1 && U.getMyCash() < amount * U.getPriceFood()) //not enough money
                        {
                            cout << "You don't have enough money" << endl;
                            cout << "How many lbs of food would you like to buy?" << endl;
                            cin >> amount;
                        }
                    }
                    break; // exit menu
           
           case 3:
           cout << "How many boxes of bullets would you like to buy, remember a box of bullets contains 20 bullets and costs" << U.getPriceBullets() << endl;
           cin >> amount;
            while (YN != 3) //asks user if they are satisfied with amount
                    {
                        cout << "Would you like to buy" << amount << "boxes? input 1 for YES, 2 for I want a different amount, or 3 to buy something else" << endl;
                        cin >> YN;
                
                        if(YN == 2) //change amount
                        {
                            cout << "How many boxes of bullets would you like to buy?" << endl;
                            cin >> amount;
                        }
                
                        if(YN == 1 && U.getMyCash() >= amount * U.getPriceBullets()) //you have enough money
                        {
                            U.changeMyCash(amount * U.getPriceBullets() * -1); //change your money
                            U.changeMyBullets(amount * 20);
                            cout << "You have" << U.getMyCash() << "cash remaining and" << U.getMyBullets() << "bullets"; 
                            break;
                        }
                
                        if(YN == 1 && U.getMyCash() < amount * U.getPriceBullets()) //not enough money
                        {
                            cout << "You don't have enough money" << endl;
                            cout << "How many boxes of bullets would you like to buy?" << endl;
                            cin >> amount;
                        }
                    }    
           break;
           
           case 4://buy wagon parts
           cout << "How many wagon parts would you like to buy, remember this includes wheels, tongues and axels. This costs" << U.getPriceParts() << endl;
           cin >> amount;
            while (YN != 3) //asks user if they are satisfied with amount
                    {
                        cout << "Would you like to buy" << amount << "parts? input 1 for YES, 2 for I want a different amount, or 3 to buy something else" << endl;
                        cin >> YN;
                
                        if(YN == 2)
                        {
                            cout << "How many parts would you like to buy?" << endl;
                            cin >> amount;
                        }
                
                        if(YN == 1 && U.getMyCash() >= amount * U.getPriceParts()) //you have enough money
                        {
                            U.changeMyCash(amount * U.getPriceParts() * -1); //change your money
                            U.changeMyParts(amount);
                            cout << "You have" << U.getMyCash() << "cash remaining and" << U.getMyParts() << "parts"; 
                            break;
                        }
                
                        if(YN == 1 && U.getMyCash() < amount * U.getPriceParts()) //not enough money
                        {
                            cout << "You don't have enough money" << endl;
                            cout << "How many Parts would you like to buy?" << endl;
                            cin >> amount;
                        }
                    }    
           break;
           
           
           case 5: //buy medKits
           cout << "How many medkits would you like to buy, remember these give you a higher chance of living when you get sick and cost" << U.getPriceMedkit() << endl;
           cin >> amount;
            while (YN != 3) //asks user if they are satisfied with amount
                    {
                        cout << "Would you like to buy" << amount << "medKits? input 1 for YES, 2 for I want a different amount, or 3 to buy something else" << endl;
                        cin >> YN;
                
                        if(YN == 2)
                        {
                            cout << "How many medkits would you like to buy?" << endl;
                            cin >> amount;
                        }
                
                        if(YN == 1 && U.getMyCash() >= amount * U.getPriceMedkit()) //you have enough money
                        {
                            U.changeMyCash(amount * U.getPriceMedkit() * -1); //change your money
                            U.changeMyMedkit(amount);
                            cout << "You have" << U.getMyCash() << "cash remaining and" << U.getMyMedkit() << "medkits"; 
                            break;
                        }
                
                        if(YN == 1 && U.getMyCash() < amount * U.getPriceMedkit()) //not enough money
                        {
                            cout << "You don't have enough money" << endl;
                            cout << "How many Medkits would you like to buy?" << endl;
                            cin >> amount;
                        }
                    }    
           break;
          
          case 6: //leave shop
          return;
          break;
        }
        
}
return;
}  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Driver::sick()
{
    int illness;
    illness = randomNumbers(1, 7);
    int who = randomNumbers(0, P.getNumAlive() - 1);
    bool die;
    int option;
    int food;
    
    switch (illness)
    {
        case 1:
        cout << "Oh no " << P.getPassenger(who) << " has the flu!" << endl;
        break;
        
        case 2:
        cout << "Oh no " << P.getPassenger(who) << " has cholera!" << endl;
        break;
        
       case 3:
        cout << "Oh no " << P.getPassenger(who) << " has diarrhea!" << endl;
        break;
        
        case 4:
        cout << "Oh no " << P.getPassenger(who) << " has dysentery!" << endl;
        break;
        
        case 5:
        cout << "Oh no " << P.getPassenger(who) << " has measles!" << endl;
        break;
        
        case 6:
        cout << "Oh no " << P.getPassenger(who) << " has covid-19!" << endl;
        break;
        
        case 7:
        cout << "Oh no " << P.getPassenger(who) << " has a fever!" << endl;
        break;
    }
    cout << "How would you like to cure " << P.getPassenger(who) << " ?" << endl;
    
    if(U.getMyMedkit() > 0) //player has a medKit
    {
        die = random(.3);
        
        if(who == 0 && die == true) //you died
        {
            cout << "You died!" << endl;
            quit == true;
            return;
        }
        else if(die == true)
        {
            cout << "Oh no you used a MedKit but " << P.getPassenger(who) << " has died" << endl;
            return;
        }
        else
        {
            cout << "You used a medkit and "  << P.getPassenger(who) << " survived!" << endl;
            return;
        }

        return;
    }
    
    else// does not have a medkit
    {
        while(option != 1 || option != 2)
        {
            cout << "Would you like to" << endl << "1. Rest" << endl << "2. Press on!" << endl;
            cin >> option;
            
            if(option == 1) //rest
            {
                die = random(.5); //50% chance of dying
            
                if(who == 0 && die == true) //you died quit game
                {
                    cout << "You died!" << endl;
                    quit == true;
                    return;
                }
                else if(die == true)
                {
                   cout << "Oh no you rested but " << P.getPassenger(who) << " has died" << endl;
                    return;
                }
                else
                {
                    cout << "You rested and "  << P.getPassenger(who) << " survived!" << endl;
                    return;
                }
                food = 9*P.getNumAlive(); // rest 3 days eat 3lbs per person
                U.changeMyFood(-food);
                cout << "You used up" << food << "lbs and have " << U.getMyFood() << "lbs remaining" << endl;
                return;
            }
            if(option == 2) //press on!
            {
                die = random(.7);//70 percent chance of dying
                
                if(who == 0 && die == true) //you died
                {
                    cout << "You died!" << endl;
                    quit == true;
                    return;
                }
                else if(die == true)
                {
                    cout << "Oh no you rested but " << P.getPassenger(who) << " has died" << endl;
                    return;
                }
                else
                {
                    cout << "You rested and "  << P.getPassenger(who) << " survived!" << endl;
                    return;
                } 
            }
            else
            {
                cout << "Please choose a valid option!" << endl;
            }
    }
}
return;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void hunt()
{
    D.add_days(1);

    int num = randomNumbers(1,100);
    int choice;
    bool puzzle;
    int food;
    if(num <= 3)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A MOOSE! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
        cin >> choice;

        if(choice == 1)
        {
            if(U.getMyBullets() < 12)
            {
                cout << "Your hunt was unsuccessful." << endl;
                return;
            }
            else
            {
                puzzle = puzzle();
                if(puzzle == true)
                {
                    food = randomNumbers(300,600);
                    cout << "Good Hunt! You gained: " << food << "lbs of food."<< endl;
                    U.changeMyFood(food);
                    U.changeMyBullets(-12);
                }
                else
                {
                    cout << "Bad hunt." << endl;
                }

            }
        }
    }

    if(num > 3 && num <= 10)
        {
            cout << "YOU GOT LUCKY! YOU ENCOUNTERED A BEAR! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
            cin >> choice;

            if(choice == 1)
            {
                if(U.getMyBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful." << endl;
                    return;
                }
                else
                {
                    puzzle = puzzle();
                    if(puzzle == true)
                    {
                        food = randomNumbers(100,350);
                        cout << "Good Hunt! You gained: " << food << "lbs of food."<< endl;
                        U.changeMyFood(food);
                        U.changeMyBullets(-10);
                    }
                    else
                    {
                        cout << "Bad hunt." << endl;
                    }

                }
            }
        }

    if(num > 10 && num <= 25)
        {
            cout << "YOU GOT LUCKY! YOU ENCOUNTERED A DEER! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
            cin >> choice;

            if(choice == 1)
            {
                if(U.getMyBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful." << endl;
                    return;
                }
                else
                {
                    puzzle = puzzle();
                    if(puzzle == true)
                    {
                        food = randomNumbers(30,55);
                        cout << "Good Hunt! You gained: " << food << "lbs of food."<< endl;
                        U.changeMyFood(food);
                        U.changeMyBullets(-5);
                    }
                    else
                    {
                        cout << "Bad hunt." << endl;
                    }

                }
            }
        }

        if(num > 25 && num <= 50)
        {
            cout << "YOU GOT LUCKY! YOU ENCOUNTERED A FOX! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
            cin >> choice;

            if(choice == 1)
            {
                if(U.getMyBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful." << endl;
                    return;
                }
                else
                {
                    puzzle = puzzle();
                    if(puzzle == true)
                    {
                        food = 5;
                        cout << "Good Hunt! You gained: " << food << "lbs of food."<< endl;
                        U.changeMyFood(food);
                        U.changeMyBullets(-8);
                    }
                    else
                    {
                        cout << "Bad hunt." << endl;
                    }

                }
            }
        }

        if(num > 50 && num <= 100)
        {
            cout << "YOU GOT LUCKY! YOU ENCOUNTERED A RABBIT! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
            cin >> choice;

            if(choice == 1)
            {
                if(U.getMyBullets() < 10)
                {
                    cout << "Your hunt was unsuccessful." << endl;
                    return;
                }
                else
                {
                    puzzle = puzzle();
                    if(puzzle == true)
                    {
                        food = 2;
                        cout << "Good Hunt! You gained: " << food << "lbs of food."<< endl;
                        U.changeMyFood(food);
                        U.changeMyBullets(-10);
                    }
                    else
                    {
                        cout << "Bad hunt." << endl;
                    }

                }
            }
        }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Driver::brokenParts()
{
    cout << "Oh no! Your wagon broke." << endl;
    
    if (U.getMyParts() > 0) //has an extra part
    {
       cout << "Thankfully you had extra parts and fixed the wagon!" << endl;
       U.changeMyParts(-1);
       cout << "You have " << U.getMyParts() << " parts remaining." << endl;
       return;
    }
    else//don't have extra parts
    {
       cout << "You are out of parts and cannot continue on the trail." << endl;
       quit = true;
       return;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Driver::oxenDies()
{
  cout << "Oh no! One of your oxen died!" << endl;
    U.changeMyOxen(-1);
    if (U.getMyOxen() > 0) //has an extra part
    {
       cout << "Thankfully you still have " << U.getMyOxen() << " remaining." << endl;
       return;
    }
    else//don't have extra parts
    {
       cout << "You are out of oxen and cannot continue on the trail." << endl;
       quit = true;
       return;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Driver::encounterFort()
{
    int option;
    int pos = M.checkAtFort();
    if(pos == -1)//not at a fort
    {
        return;
    }
    else //at a fort
    {
        while(option != 3)
        {
            cout << "You have reached " << M.getFortName(pos) << endl << "Please choose an option:" << endl << "1. Rest" << endl << "2. Visit the store" << endl << "3. Continue" << endl;
            cin >> option;
            if(option == 1)
            {
                //change date
                //eat food?
            }
            if(option == 2)
            {
                shop();
            }
        }
        return;
    }   
    


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Driver::encounterRiver()
{
    int option;
    int pos = M.checkAtRiver(); //river pos or -1
    if(pos == -1) //not at a river
    {
        return;
    }
    else//at a river
    {
        while(option != 2) //loop untill cross
        {
            cout << "You have reached " << M.getRiverName(pos) << endl << "Choose and option" << endl << "1. Rest" << "2. Cross" << endl;
            cin >> option;
            if(option == 1) //rest
            {
                //change date to 1 days 
                
            }
            else if(option == 2) //continue
            {
                if(M.getRiverDepth(pos) >= 3)
                {
                    cout << "You need to take ferry to cross, this will cost you $10" << endl;
                    if(U.getMyCash() >= 10) //you can afford it
                    {
                        U.changeMyCash(-10);
                        cout << "Thank you!" << endl;
                        cout << "Cash remaining: " << U.getMyCash();
                    }
                    else //can't afford trip
                    {
                      cout << "You coudn't afford th trip so you decided to ask for help" << endl;
                      cout << "Oh someone gave you $10!" << endl; //maybe kill and oxen instead and make the trip across the river lol
                    }
                }
                cout << "You successfully crossed the river!" << endl;
                return;
            }
            else
            {
                cout << "Please enter a valid option" << endl;
            }
    
}
}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Driver::checkGame()
{
    if(quit == true)
    {
        return true;
    }
    else//game over
    {
        return false;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Driver::endTurn() //returns 1 if met fort, 2 if met river milestone, 0 if niether
{
    int turnMiles = randomNumbers(90,140); // after a turn you travel 100-140 miles
   //change date up 14 days
   
   if (M.getFortMileage(M.nextFort()) < M.getRiverMileage(M.nextRiver())) //Fort is closest milestone
    {
        if(turnMiles >= M.getFortMileage(M.nextFort())) //reached a fort
        {
        turnMiles = M.getFortMileage(M.nextFort());
        M.changeMileage(turnMiles);
        //reach a milestone
        return 1;
        }
        
    }
   else if(M.getFortMileage(M.nextFort()) > M.getRiverMileage(M.nextRiver())) //next milestone is a river
   {
     if(turnMiles >= M.getRiverMileage(M.nextRiver())) //reached a fort
        {
        turnMiles = M.getRiverMileage(M.nextRiver());
        M.changeMileage(turnMiles);
        //reach a milestone river
        return 2;
        } 
   }
   
   M.changeMileage(turnMiles);
   cout << "You traveled " << turnMiles << "mi and have traveled " << M.getTotalMileage() << "mi total" << endl;
   cout << "Your next milestone is: ";
   
   if(M.getFortMileage(M.nextFort()) < M.getRiverMileage(M.nextRiver())) //fort is closest
   {
       cout << M.getFortName(M.nextFort()) << " and is " << M.getFortMileage(M.nextFort()) - M.getTotalMileage() << "mi away." << endl;
   }
   else//next river is closer
   {
      cout << M.getRiverName(M.nextRiver()) << " and is " << M.getRiverMileage(M.nextRiver()) - M.getTotalMileage() << "mi away" << endl;
   }
   return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Driver::exitGame()
{
        M.winGame();
}
