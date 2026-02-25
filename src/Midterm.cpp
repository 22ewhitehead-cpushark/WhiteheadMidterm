#include <iostream>
#include <string>
#include "Player.h"

using namespace std; 

int main(){
    int playerCount = 1;
    bool valid = true;
    cout << "Welcome to my Casino! We only have one game. It is a number guessing game.\n"
     "Here is $100 to start. First you place a bid. Then you guess a number between 1-20.\n" 
     "If you guess the number correctly, you get 3 times the amount of money. If your guess is within 5 of the numbee, your money is doubled.\n"
     "If your guess is 6 or more away from the number, you lose your bid. Simple right? Even better is you can play with other people!\n";
    
    while (valid){
        cout<< "How many people are playing? (Only a maximum of 5 players can play)\n";
        cin>> playerCount;
        if (playerCount == 1 || playerCount == 2 || playerCount == 3 || playerCount == 4 || playerCount == 5){
            valid = false;
            break;
        }
        else{
            cout << "Invalid player number.\n";
            valid = true;
        }

    }



    return 0;
}