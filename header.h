//In the main random is going to be a funciton

/*class misfortune{
    public:
        //going to set random to 1-10
        //set choice 1-3
        misfortune();
        //choses which misfortune to do based off of choice
        //This method will be using other classes to add subtract reasources, rest, etc.
        void getmisfortune();
    private:
        int random;
        int choice;
};*/

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

class time_1{
    private:
        int date[3];
    public:
        time_1();
        void get_date();
        bool over_time();
        void set_date(int, int, int);
        void add_days(int);
};


