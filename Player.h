#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Player
{
    private:
    string player;
    string passenger1;
    string passenger2;
    string passenger3;
    string passenger4;
    string people[5];
    int numAlive;
    bool meAlive;
    
    public:
    
    Player();//sets usernames and sets values of utilities to zero and cash to 1200 AND numAlive to 5
    
    void setPlayer(string,string,string,string,string); // player, passenger1, passenger2, passenger3, passenger4
    
    string getPlayer(); //returns name of player
    
    string getPassenger1(); //outputs name of passanger1
    
    string getPassenger2(); //outputs name of passanger2
    
    string getPassenger3();//outputs name of passanger3
    
    string getPassenger4();//outputs name of passanger4
    
    string getPassenger(int); //input player posotion outputs player
    
    int getNumAlive();
    
    void peopleDied(int); //input array position of person who died, if 0 it is you
    void changeMeAlive();
    
    
};

