//
// Created by sauser on 23.12.2024.
//
//Includes
#include <iostream>
#include "../../includes/UserInput.h"

using namespace std;


//Functions
int creatingMenu();

void startNewBlackjackGame();


//struct for the blackjack cards for the dealer
typedef struct _dealerCard_ {
    int cardValue;
    struct _dealersCard *next;
} dealersCard;

typedef struct _playerCard_ {
    int cardValue;
    struct _playersCard *next;
}  playersCard;

dealersCard *allDealerCards; //saves a list global for all the dealers cards
dealersCard *firstDealerCard; //saves the first element which won't change

playersCard *allPlayerCards;
playersCard *firstPlayerCard;

bool mainFunctionBlackjack() {
   bool endBlackjack = false;
   int decision;

   do {
       decision = creatingMenu();

       switch (decision) {
           case 0: {
               cout << "Goodbye!" << endl;
               return true;
           }
           case 1: {
               return false;
           }
           case 2: {
               startNewBlackjackGame();
           }
       }
   } while (!endBlackjack);
   return true;
}

int creatingMenu() {
    cout << "Please choose what do you want to do:" << endl;
    cout << "---------- 0. End the game ----------" << endl;
    cout << "----- 1. Return to the main menu ----" << endl;
    cout << "---------- 2. Play the game ---------" << endl;
    return checkUserInputInteger();
}

void startNewBlackjackGame() {

}


