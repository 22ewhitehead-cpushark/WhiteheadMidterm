#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

string Player::getName() const{
    return name;
};

int Player::getGuess() const{
    return guess;
};

double Player::getMoney() const{
    return money;
};