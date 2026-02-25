#pragma once

#include <string>

using namespace std;

class Player{
    private:
        string name;
        int guess;
        double money = 100;
    public:
        Player(){};
        Player(string name, int guess, double money): name(name), guess(guess), money(money){};

        void setName(string name){};
        void setMoney(double money){};
        void setGuess(int guess){};

        string getName() const;
        double getMoney() const;
        int getGuess() const;

        
    
};