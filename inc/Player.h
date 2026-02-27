#pragma once

#include <string>

using namespace std;

class Player{
    private:
        string name;
        int guess;
        double money = 100;
        double bid = 0;
    public:
        Player(){};
        Player(string name, int guess, double money): name(name), guess(guess), money(money){};

        void setName(string name){};
        void setMoney(double money){};
        void setGuess(int guess){};
        void setBid(double bid){};

        string getName() const;
        double getMoney() const;
        int getGuess() const;
        double getBid() const;

        friend istream& operator>>(istream& in, Player& player){
            char colon;
            in >> player.bid >> colon >> player.guess;
            return in;
        }
    
};