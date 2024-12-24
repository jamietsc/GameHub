//
// Created by sauser on 24.12.2024.
//

#ifndef ZAHLENRATEN_SPIEL_NUMBERGUESSING_H
#define ZAHLENRATEN_SPIEL_NUMBERGUESSING_H

#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <utility>

using namespace std;

bool checkNumber(int, int );
int checkUserInputInteger();
bool playingAgain();
char checkUserInputChar();
string inputOfTheUsername();
void readUsernameAndHighscore();
void saveNewUsernameAndHighscore(const vector<pair<string, int>>& );
void checkIfUserHasNewHighscore(const string&);
bool isEmpty(ifstream& );
int creatingMenu();

#endif //ZAHLENRATEN_SPIEL_NUMBERGUESSING_H
