#pragma once

#include <string>

using namespace std;

class Player{
    private:
        string name;
        int guess;
        double money = 100;
        double bid = 0;
        bool again = true;
    public:
        Player(){};
        Player(string name, int guess, double money, double bid){};

        void setName(string name){
            this->name = name;
        };
        void setMoney(double mone){
            money = mone;
        };
        void setGuess(int gues){
            guess = gues;
        };
        void setBid(double bi){
            bid = bi;
        };
        void setAgain(bool agai){
            again = agai;
        }

        string getName();
        double getMoney() const;
        int getGuess() const;
        double getBid() const;

        friend istream& operator>>(istream& in, Player& player){
            char colon;
            in >> player.bid >> colon >> player.guess;
            return in;
        }
    
};