#include <iostream>
#include <string>
#include "Player.h"

using namespace std; 

int main(){
    int playerCount = 1;
    bool valid = true;
    int i=1;
    Player player1;
    Player player2;
    Player player3;
    cout << "Welcome to my Casino! We only have one game. It is a number guessing game.\n"
     "Here is $100 to start. First you place a bid. Then you guess a number between 1-20.\n" 
     "If you guess the number correctly, you get 3 times the amount of money. If your guess is within 5 of the numbee, your money is doubled.\n"
     "If your guess is 6 or more away from the number, you lose your bid. Simple right? Even better is you can play with other people!\n";
    
    while (valid){
        cout<< "How many people are playing? (Only a maximum of 3 players can play)\n";
        cin>> playerCount;
        if (playerCount == 1 || playerCount == 2 || playerCount == 3){
            valid = false;
            break;
        }
        else{
            cout << "Invalid player number.\n";
            valid = true;
            continue;
        }
    }
    cout<< "Excellent! you have chosen: " << playerCount << "person/people to play, we will now enter their names.\n";
    while(playerCount>i){
        string playerName;
        cout<< "What is player "<< i <<"s name?\n";
        cin >> playerName;
        if (i==1){
            player1.setName(playerName);
        }
        else if(i==2){
            player2.setName(playerName);
        }
        else if (i==3){
            player3.setName(playerName);
        }
        else{
            cout<< "playerNumbers are messed up";
        }

        i+=1;
    }



    return 0;
}