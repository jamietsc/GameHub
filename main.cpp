#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <utility>


#include "games/numberGuessing/NumberGuessing.h"
#include "includes/UserInput.h"
#include "games/Blackjack/Blackjack.h"

using namespace std;

bool checkNumber(int input, int x);
bool playingAgain();
string inputOfTheUsername();
void readUsernameAndHighscore();
void saveNewUsernameAndHighscore(const vector<pair<string, int>>& highscores);
void checkIfUserHasNewHighscore(const string& username);
bool isEmpty(ifstream& myFile);
int creatingMainMenu();

int main() {
    bool end = false;// variable to end the loop
    int decision; //decision is for the menu of the game
    string username;

    do {
        decision = creatingMainMenu();

        switch (decision) {
            case 0: {
                cout << "Goodbye!" << endl;
                return 1;
            }
            case 1: {
                end = mainFunctionNumberGuessing();
            }
            case 2: {
                end = mainFunctionBlackjack();
                break;
            }
            default: {
                cout << "Your input was not accepted by the program, please try again." << endl;
            }
        }
    } while (!end);
    return 0;
}

int creatingMainMenu(){
    cout << "Please choose what do you want to do:" << endl;
    cout << "----------- 0. End GameHub ----------" << endl;
    cout << "------ 1. Play Number Guessing ------" << endl;
    cout << "--------- 2. Play Blackjack ---------" << endl;

    return checkUserInputInteger();
}
