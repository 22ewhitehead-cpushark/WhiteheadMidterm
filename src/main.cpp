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

void calcResults(int guess, double bid, double money, int compNum, string name, Player player){
    money -= bid;
    if (guess == compNum){
        money += (bid*3);
        cout << name << " has guessed it correctly! Their money is tripled. They now have $"<< money<<endl;
    }
    else if ((compNum - guess <=3 && compNum - guess > 0) || (guess- compNum <=3 && guess - compNum > 0)){
        money += (bid*2);
        cout << name << " was within 3 of the number! Their money has doubled.They now have $"<< money<<endl;
    }
    else{
        cout << name << " wasn't close enough and has lost their money.They now have $"<< money<<endl;
    }
    player.setMoney(money);
}
void playAgain(Player player){
    bool again;
    string result;
    if(player.getMoney() == 0){
        cout << player.getName() << " is out of money and cannot play another round.\n";
    }
    else{
    cout<< player.getName() << ", do you want to play another round? (y/n)\n";
    cin >> result;
    if (result != "y"){
        again = false;
    }
    }
    player.setAgain(again);
}


int main(){
    string playerCountS;
    string playerCountJr;
    double playerBid = 0;
    int playerGuess, playerNum;
    bool valid = true;
    int i=1;
    bool haveMoney = true;
    bool playAgain = true;
    Player player1;
    Player player2;
    Player player3;
    int compNum;
    cout << "Welcome to my Casino! We only have one game. It is a number guessing game.\n"
     "Here is $100 to start. First you place a bid. Then you guess a number between 1-20.\n" 
     "If you guess the number correctly, you get 3 times the amount of money. If your guess is within 5 of the numbee, your money is doubled.\n"
     "If your guess is 4 or more away from the number, you lose your bid. Simple right? Even better is you can play with other people!\n";
    
    do {
        cout<< "How many people are playing? (Only a maximum of 3 players can play)\n";
        cin>> playerCountS;
        if (playerCountS == "1" || playerCountS == "2" || playerCountS == "3"){
            valid = false;
            break;
        }
        else{
            cout << "Invalid player number.\n";
            valid = true;
            //continue;
        }
        //cin.clear(playerCount);
    } while (valid);
    int playerCount = stoi(playerCountS);

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
    /*while (playAgain){
        if (player1.getMoney() > 0 && player2.getMoney() > 0 && player3.getMoney()>0){
            haveMoney = true;
        }
        else{
            cout << "It would appear what one of the players is out of money.";
        }
        while (haveMoney){
            
        }
    }*/
    cout << "Now lets get those bids and guesses!\n";
    do{cout << player1.getName() << ", what is your bid and guess? (bid:guess)\n";
    cin >> player1;
    }while(!(checkBid(player1.getMoney(), player1.getBid()) && checkGuess(player1.getGuess())));
    cout << player1.getName() << " bid $" << player1.getBid() << " and guessed " << player1.getGuess()<< endl;
    if (playerCount>=2){
        do{cout << player2.getName() << ", what is your bid and guess? (bid:guess)\n";
        cin >>player2;
        }while(!(checkBid(player2.getMoney(), player2.getBid()) && checkGuess(player2.getGuess())));
        if (playerCount == 3){
            do{cout << player3.getName() << ", what is your bid and guess? (bid:guess)\n";
            cin >> player3;
            }while(!(checkBid(player3.getMoney(), player3.getBid()) && checkGuess(player3.getGuess())));
        }
    }
    compNum = getComputerNumber();
    cout << "Let's check those results. \n";
    calcResults(player1.getGuess(), player1.getBid(), player1.getMoney(), compNum, player1.getName(), player1);
    if (playerCount >=2){
        calcResults(player2.getGuess(), player2.getBid(), player2.getMoney(), compNum, player2.getName(), player2);
        if (playerCount == 3){
            calcResults(player3.getGuess(), player3.getBid(), player3.getMoney(), compNum, player3.getName(), player3);
        }
    }

    return 0;
}