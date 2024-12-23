#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <fstream>
#include <random>

using namespace std;

bool checkNumber(int input, int x);
int checkUserInputInteger();
bool playingAgain();
char checkUserInputChar();
string inputOfTheUsername();
void readUsernameAndHighscore();
void saveNewUsernameAndHighscore(string username);
void checkIfUserHasNewHighscore(string username);
bool isEmpty(ifstream& myFile);

int trys = 0;

int main() {
    bool end = false;// variable to end the loop
    int input, //input is for saving the guess of the user. trys for counting the trys the user needed
        x, //x is the random number between 1 and 100
        decision; //decision is for the menu of the game
    string username;


    username = inputOfTheUsername();

    do {
        mt19937 rng(random_device{}());
        uniform_int_distribution<int> dist(1, 100);
        x = dist(rng);

        cout << "The number is set between 1 and 100, you can write your answer now." << endl;

        while (!end) {
            input = checkUserInputInteger();
            if(input > 0){
                end = checkNumber(input, x);
            }
        }

        checkIfUserHasNewHighscore(username);

        end = playingAgain();
    } while (!end);
    return 0;
}

/**
 * function to check the number from the user
 * @param input the input from the user
 * @param x the number that has to be guess
 * @return true if correct, false if not correct
 */
bool checkNumber(int input, int x) {
    trys++;
    if(input < x){
        cout << "The random number is bigger than your input." << endl;
        cout << "Please guess again: " << endl;
        return false;
    } else if(input > x){
        cout << "The random number is smaller than your input." << endl;
        cout << "Please guess again: " << endl;
        return false;
    } else if(input == x){
        cout << "Congratulations, you guessed the right number." << endl;
        cout << "You needed " << trys << " trys to guess the right number." << endl;
        return true;
    } else {
        cout << "An error has occurred, the program will shut down." << endl;
        return true;
    }
}

/**
 * function which checks if the user input is an integer or not
 * if the input is not an int the user have to insert a value again
 * @return the input if it is an integer
 */
int checkUserInputInteger(){
    int input;
    bool correctInput = false;

    cin >> input;
    do{
        if(cin.fail()){
            cin.clear(); //reset the error
            cin.ignore(256, '\n'); //empty insert puffer
            cout << "Please insert only full numbers. Please try again." << endl;
        } else {
            correctInput = true;
        }
    } while (!correctInput);
    return input;
}

/**
 * function to check if the user input is a single char
 * @return the single char
 */
char checkUserInputChar(){
    char input;
    bool correctInput = false;

    while (!correctInput) {
        cin >> input;
        if(cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please insert only one letter. Try again:" << endl;
        } else if (!isalpha(input)){
            cout << "Please insert only one letter. Try again:" << endl;
        } else {
            correctInput = true;
        }
    }
    return input;
}

/**
 * function for the user to decide if he wants to play again or not
 * @return false if he wants to play again; true if he wants to stop
 */
bool playingAgain() {
    char decision;

    cout << "Do you want to play again? (yes = y; no = n)" << endl;

    while (true) {
        decision = checkUserInputChar();

        if (decision == 'y') {
            trys = 0;
            return false;
        } else if (decision == 'n') {
            return true;
        } else {
            cout << "This letter was not accepted by the program. Please try again: " << endl;
        }
    }
}

/**
 * function to insert the username and accept it
 * @return the username to the function call
 */
string inputOfTheUsername(){
    string username;
    char decision;

    while(true){
        cout << "Please insert your name." << endl;
        cin >> username;
        cout << "Your inserted username is: " << username << ". Do you want to play with it (Yes = y; No = n)" << endl;
        while (true) {
            decision = checkUserInputChar();
            if (decision == 'y') {
                return username;
            } else if (decision == 'n') {
                break;
            } else {
                cout << "This letter was not accepted by the program. Please try again: " << endl;
            }
        }
    }
}

/**
 * function to read the username and his highscore from the highscore.txt file
 */
void readUsernameAndHighscore() {
    string bestUser[2];
    ifstream myFile ("..\\highscore.txt");

    if(isEmpty(myFile)){
        cout << "Wow, you are the first one who is playing the game. There was no one before you who could be better!!" << endl;
        return;
    }

    if(myFile.is_open()) {
        if(!getline(myFile, bestUser[0])) {
            cout << "Error: Could not read the username out of the file." << endl;
            return;
        }
        if(!getline(myFile, bestUser[1])) {
            cout << "Error: Could not read the highscore out of the file." << endl;
            return;
        }

        cout << "The best user was " << bestUser[0]
            << ". He needed only " << bestUser [1]
            << " trys to guess the right number." << endl;
        myFile.clear();
    } else {
        cout << "Unable to open the highscore file." << endl;
    }
}

/**
 * function to save the new username and highscore in the text file.
 * @param username username which should be saved
 */
void saveNewUsernameAndHighscore(string username) {
    ofstream myFile ("..\\highscore.txt");
    if(myFile.is_open()) {
        myFile << username << "\n";
        myFile << trys;
        myFile.close();
        cout << "New Highscore got saved, you are at the top of the leaderboard now." << endl;
    } else {
        cout << "Unable to open the highscore file." << endl;
    }
}

/**
 * function to check if the user got the new highscore
 * @param username if the user got the highscore the function calls a function where the new username is needed
 */
void checkIfUserHasNewHighscore(string username) {
    string bestUser[2];
    ifstream myFile ("..\\highscore.txt");

    if(isEmpty(myFile)){
        cout << "Wow, you are the first one who is playing the game. There was no one before you who could be better!!" << endl;
        saveNewUsernameAndHighscore(username);
        return;
    }

    if(myFile.is_open()) {
        if(!getline(myFile, bestUser[1])) {
            cout << "Error: Could not read the highscore out of the file." << endl;
        }

        if(trys >= atoi( bestUser[1].c_str())) {
            cout << "Sorry you are not the best of the game." << endl;
        } else if (trys < atoi(bestUser[1].c_str())) {
            cout << "Congratulations, you got the new Highscore, it will be saved under your name" << endl;
            saveNewUsernameAndHighscore(username);
        }
    } else {
        cout << "Unable to open the highscore file." << endl;
    }
}

/**
 * Function to check if an excisting file is empty
 * @param myFile the path of the file
 * @return true if its empty || false if its not empty
 */
bool isEmpty(ifstream& myFile) {
    return myFile.peek() == ifstream::traits_type::eof();
}
