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

        string getName() const;
        double getMoney() const;
        int getGuess() const;

        
    
};