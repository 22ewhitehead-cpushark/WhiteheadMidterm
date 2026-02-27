#include <string>
#include <iostream>
#include "Player.h"

using namespace std;


void setName(string name){
    name = name;
};
void setMoney(double money){
    money = money;
};
void setGuess(int guess){
    guess = guess;
};

void setBid(double bid){
    bid = bid;
}


string Player::getName() const{
    return name;
};

int Player::getGuess() const{
    return guess;
};

double Player::getMoney() const{
    return money;
};

double Player::getBid() const{
    return bid;
}