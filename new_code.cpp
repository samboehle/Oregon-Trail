class raider{
    public:
        raider();
        
        //takes in mileage and outputs weather a radier attack will happen
        bool getraider(int);

        //call this if user choses to run
        //run() will take away all the reasources listed in the write up
        void run();

        //will need to call puzzle class or puzzle function
        void attack();

        //takes away cash
        void surrender();

    private:
        bool is_attack;
};

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