#include "Player.h"
using namespace std;
Player::Player()
{
    player = "";
    passenger1 = "";
    passenger2 = "";
    passenger3 = "";
    passenger4 = "";
    people[0] = "";
    people[1] = "";
    people[2] = "";
    people[3] = "";
    people[4] = "";
}

///////////////////////////////////////////////////////////////////////////////
 void Player::setPlayer(string player, string passenger1, string passenger2,string passenger3,string passenger4)
 {
     
     this -> player = player;
     this -> passenger1 = passenger1;
     this -> passenger2 = passenger2;
     this -> passenger3 = passenger3;
     this -> passenger4 = passenger4;
     
    meAlive = true;
    
    people[0] = player;
    people[1] = passenger1;
    people[2] = passenger2;
    people[3] = passenger3;
    people[4] = passenger4;
    
    numAlive = 5;
 
}

/////////////////////////////////////////////////////////

string Player::getPlayer()
{
    return people[0];
}
///////////////////////////////////////////////////////////////////////////////
string Player::getPassenger1()
{
    return people[1];
}

///////////////////////////////////////////////////////////////////////////////

string Player::getPassenger2()
{
    return people[2];
}
////////////////////////////////////////////////////////////////////////////////

string Player::getPassenger3()
{
    return people[3];
}
///////////////////////////////////////////////////////////////////////////////
string Player::getPassenger4()
{
    return people[4];
}
///////////////////////////////////////////////////////////////////////////////
string Player::getPassenger(int x)
{
   return people[x];
}
///////////////////////////////////////////////////////////////////////////////
  int Player::getNumAlive() //outputs number of people alive
  {
      return numAlive;
  }  
////////////////////////////////////////////
    
void Player::peopleDied(int pos)
{
    
    if(pos == 0) //you have died
    {
       cout << "Oh no you have died GAME OVER!";
       meAlive = false;
       return;
    }
    
    cout << "Oh no " << people[pos] << " has died! Only " << numAlive <<" passangers remain!" << endl;
    
    people[pos] = "*DEAD*";
    numAlive = numAlive - 1;
    string Fpeople[numAlive]; //shorten array
    
    int y = 0;
    
    for(int x = 0; x < numAlive; x++) //create new array and get rid of dead
    {
        if(people[x].compare("*DEAD*") == 0)//this player is dead
        {
            y++;
        }
        
        Fpeople[x] = people[y];
        y++;
    }
    
    for(int x = 0; numAlive > x; x++) //people[] become Fpeople[]
    {
        people[x] = Fpeople[x];
    }
    
}
/////////////////////////////////////////////////////////////
void Player::changeMeAlive()
{
meAlive = false;
}
///////////////////////////////////////////////////////////
