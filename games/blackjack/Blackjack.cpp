//
// Created by sauser on 23.12.2024.
//
//Includes
#include <iostream>
#include <random>

#include "../../includes/UserInput.h"

//namespaces which are used in the code
using namespace std;

// Struct for linked list
struct Card {
    int cardValue;
    string fourColorName;
    string nameOfTheCard;
    Card* next;
};

// Globals for dealer and player cards
Card* dealerCards = nullptr;
Card* playerCards = nullptr;

//functions
int creatingBlackjackMenu();

void startNewBlackjackGame();

void addCardDealer();

void addCardPlayer();

Card* generateCard();


bool mainFunctionBlackjack() {
   bool endBlackjack = false;
   int decision;

   do {
       decision = creatingBlackjackMenu();

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
               break;
           }
           case 3: {
               Card* playersCard = new Card();
               playersCard = generateCard();
               cout << "The card u pulled is a " << playersCard->fourColorName << playersCard->nameOfTheCard << ".";
           }
       }
   } while (!endBlackjack);
   return true;
}

int creatingBlackjackMenu() {
    cout << "Please choose what do you want to do:" << endl;
    cout << "---------- 0. End the game ----------" << endl;
    cout << "----- 1. Return to the main menu ----" << endl;
    cout << "---------- 2. Play the game ---------" << endl;
    return checkUserInputInteger();
}

void startNewBlackjackGame() {
    cout << "Starting a new game..." << endl;
    dealerCards = nullptr;
    playerCards = nullptr;


}

void addCardDealer() {

}

void addCardPlayer() {

}

Card* generateCard(){
    string theFourTens[] = {"Ten", "Jack", "Queen","King"};
    string theFourColors[] = {"Heart", "Diamond", "Spade", "Clubs"};
    string cardNames[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 11);
    uniform_int_distribution<int> arrayForFour(0, 3);


    Card* newCard = new Card();
    newCard->cardValue = dist(rng);

    if(newCard->cardValue == 1 || newCard->cardValue == 11) {
        newCard->nameOfTheCard = "Ace";
    } else if (newCard->cardValue >= 2 && newCard->cardValue <= 9){
        newCard->nameOfTheCard = cardNames[newCard->cardValue - 2];
    } else if (newCard->cardValue == 10) {
        newCard->nameOfTheCard = theFourTens[arrayForFour(rng)];
    }

    newCard->fourColorName = theFourColors[arrayForFour(rng)];
    return newCard;
}




