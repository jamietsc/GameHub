#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <utility>
#include "includes/numberGuessing.h"

using namespace std;

bool checkNumber(int input, int x);
int checkUserInputInteger();
bool playingAgain();
char checkUserInputChar();
string inputOfTheUsername();
void readUsernameAndHighscore();
void saveNewUsernameAndHighscore(const vector<pair<string, int>>& highscores);
void checkIfUserHasNewHighscore(const string& username);
bool isEmpty(ifstream& myFile);
int creatingMainMenu();

int trys = 0;

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
                mainFunctionNumberGuessing();
            }
            case 2: {
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
    int input; // the input of the user, respectively his decision
    cout << "Please choose what do you want to do:" << endl;
    cout << "----------- 0. End GameHub ----------" << endl;
    cout << "------ 1. Play Number Guessing ------" << endl;


    return checkUserInputInteger();
}
