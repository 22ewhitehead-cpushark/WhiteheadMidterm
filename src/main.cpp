#include <iostream>
#include <string>
#include "Player.h"
#include <ctime>

using namespace std; 

bool checkBid(double playerMoney, double bid){
    bool valid = true;
    if (bid > playerMoney){
        cout << "Invalid bid. Not enough money.\n";
        cout << "You have: $" << playerMoney << endl;
        valid = false;
    }
    return valid;
}

bool checkGuess(int guess){
    bool valid = true;
    if (!(guess >0 && guess <21)){
        cout<<"invalid guess. Please pick a number between 1-20.\n";
        valid = false;
    }
    return valid;
};

int getComputerNumber(){
    int compNumber = 1;
    compNumber = rand()% 20 + 1;
    return compNumber;
}



int main(){
    int playerCount;
    double playerBid = 0;
    int playerGuess;
    bool valid = true;
    int i=1;
    bool haveMoney = true;
    bool playAgain = true;
    Player player1;
    Player player2;
    Player player3;
    cout << "Welcome to my Casino! We only have one game. It is a number guessing game.\n"
     "Here is $100 to start. First you place a bid. Then you guess a number between 1-20.\n" 
     "If you guess the number correctly, you get 3 times the amount of money. If your guess is within 5 of the numbee, your money is doubled.\n"
     "If your guess is 6 or more away from the number, you lose your bid. Simple right? Even better is you can play with other people!\n";
    
    do {
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
    } while (!(playerCount<4 && playerCount > 0));
    
    cout<< "Excellent! you have chosen: " << playerCount << " person/people to play, we will now enter their names.\n";
    while(playerCount>=i){
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
            break;
        }
        else{
            cout<< "playerNumbers are messed up";
        }
        i+=1;
    }
    while (playAgain){
        if (player1.getMoney() > 0 && player2.getMoney() > 0 && player3.getMoney()>0){
            haveMoney = true;
        }
        else{
            cout << "It would appear what one of the players is out of money.";
        }
        while (haveMoney){
            
        }
    }
    cout << "Now lets get those bids and guesses!";
    cout << player1.getName() << " what is your bid and guess? (bid:guess)\n";
    cin >> player1;
    if (playerCount>=2){
        cout << player2.getName() << " what is your bid and guess? (bid:guess)\n";
        cin >>player2;
        if (playerCount == 3){
            cout << player2.getName() << " what is your bid and guess? (bid:guess)\n";
            cin >> player3;
        }
    }


    return 0;
}