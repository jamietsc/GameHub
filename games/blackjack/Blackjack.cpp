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
    struct Card* next_;
};

// Globals for dealer and player cards
Card* dealerCards = nullptr;
Card* playerCards = nullptr;

Card *firstDealerCard;
Card *firstPlayerCard;

//functions
int creatingBlackjackMenu();

void startNewBlackjackGame();

void addCardDealer();

void addCardPlayer();

Card* generateCard();

void printDealerCards();

void printPlayerCards();

void printDealersFirstCard();

void hit();

void stand();

void doubleDown();

void split();

void surrender();

bool checkIfPlayerIsOver21();

bool checkIfPlayerHasBlackjack();

bool checkIfDealerHasBlackjack();

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
               printDealerCards();
               break;
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
    bool blackjackGameEnds = false;
    int decision;

    cout << "Starting a new game..." << endl;
    dealerCards = nullptr;
    playerCards = nullptr;

    addCardPlayer();
    addCardDealer();

    printDealersFirstCard();

    printPlayerCards();

    while(!blackjackGameEnds){
        cout << "What is your next play?" << endl;
        cout << "- 0. Read your cards. -"
        cout << "-------- 1. Hit -------" << endl;
        cout << "------- 2. Stand ------" << endl;
        cout << "---- 3. Double Down ---" << endl;
        cout << "------- 4. Split ------" << endl;
        cout << "----- 5. Surrender ----" << endl;

        decision = checkUserInputInteger();

        switch (decision) {
            case 0: {
                printPlayerCards();
                break;
            }
            case 1: {
                addCardPlayer();
                checkIfPlayerIsOver21();
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                surrender();
                break;
            }
            default: {
                cout << "Your input was not accepted by the system. Please try again." << endl;
                break;
            }
        }
    }





}

void addCardDealer() {
    Card* generatedCard;
    if(dealerCards == nullptr){
        for(int i = 0; i <= 1; i++){
            generatedCard = generateCard();
            if(dealerCards == nullptr){
                firstDealerCard = generatedCard;
                dealerCards = generatedCard;
                cout << "The first Card of the dealer is: " << dealerCards->fourColorName << " "
                     << dealerCards->nameOfTheCard << "." << endl;
                dealerCards->next_ = nullptr;
            } else {
                dealerCards = firstDealerCard;
                while (dealerCards != nullptr) {
                    if(dealerCards->next_ == nullptr) {
                        dealerCards->next_ = generatedCard;
                        break;
                    } else {
                        dealerCards = dealerCards->next_;
                    }
                }
            }
        }
    } else {
        dealerCards = firstDealerCard;
        while (dealerCards != nullptr) {
            if(dealerCards->next_ == nullptr) {
                dealerCards->next_ = generatedCard;
                break;
            } else {
                dealerCards = dealerCards->next_;
            }
        }
    }
}


void addCardPlayer() {
    Card* generatedCard;
    if(playerCards == nullptr){
        for(int i = 0; i <= 1; i++){
            generatedCard = generateCard();
            if(playerCards == nullptr){
                firstDealerCard = generatedCard;
                playerCards = generatedCard;
                cout << "You pulled: " << playerCards->fourColorName << " " << playerCards->nameOfTheCard << "." << endl;
                playerCards->next_ = nullptr;
            } else {
                playerCards = firstDealerCard;
                while (playerCards != nullptr) {
                    if(playerCards->next_ == nullptr) {
                        playerCards->next_ = generatedCard;
                        cout << "You pulled: " << playerCards->next_->fourColorName << " " << playerCards->next_->nameOfTheCard << "." << endl;
                        break;
                    } else {
                        playerCards = playerCards->next_;
                    }
                }
            }
        }
    } else {
        generatedCard = generateCard();
        playerCards = firstDealerCard;
        while (playerCards != nullptr) {
            if(playerCards->next_ == nullptr){
                playerCards->next_ = generatedCard;
                cout << "You pulled: " << playerCards->next_->fourColorName << " " << playerCards->next_->nameOfTheCard << "." << endl;
                break;
            } else {
                playerCards = playerCards->next_;
            }
        }
    }


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

void printDealerCards(){
    dealerCards = firstDealerCard;
    while(dealerCards != nullptr){
        cout << "The dealer pulled: " << dealerCards->fourColorName << " " << dealerCards->nameOfTheCard << "." << endl;
        dealerCards = dealerCards->next_;
    }
    delete(dealerCards);
}

void printPlayerCards() {
    int i = 1;
    playerCards = firstPlayerCard;
    while(i < 3){
        cout << "On your hand you have: " << endl;
        cout << i << ". " << playerCards->fourColorName << " " << playerCards->nameOfTheCard << "." << endl;
        playerCards = playerCards->next_;
        i++;
    }
}

void printDealersFirstCard(){
    cout << "The dealer has the following card on his hand: " << endl;
    cout << "1. " << firstDealerCard-> fourColorName << " " << firstDealerCard->nameOfTheCard << endl;
}

void hit() {

}

void stand() {

}

void doubleDown() {

}

void split() {

}

void surrender() {

}

bool checkIfPlayerIsOver21() {
    int value = 0;
    playerCards = firstPlayerCard;
    while(playerCards->next_ != nullptr){
        value = value + playerCards->cardValue;
    }

    if(value <= 21){
        return false;
    } else {
        return true;
    }
}





