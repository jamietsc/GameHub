#include <iostream>
#include <cstdlib>
#include <limits>

bool checkNumber(int input, int x);
int checkUserInputInteger();
bool playingAgain();
char checkUserInputChar();

using namespace std;

int main() {
    int x;
    bool end = false;// variable to end the loop
    int input; //input is for saving the guess of the user. trys for counting the trys the user needed.

    do {
        x = rand() % 100 + 1; //x is the random number between 1 and 100
        cout << "The number is set between 1 and 100, you can write your answer now." << endl;

        input = checkUserInputInteger();
        if(input > 0){
            end = checkNumber(input, x);
        }

        if(end) {
            end = playingAgain();
        }

    } while (end == false);
    return 0;
}

/**
 * function to check the number from the user
 * @param input the input from the user
 * @param x the number that has to be guess
 * @return true if correct, false if not correct
 */
bool checkNumber(int input, int x) {
    int trys = 0;

    trys++;
    if(input < x){
        cout << "The random number is bigger than your input." << endl;
        cout << "Please guess again: " << endl;
        return false;
    } else if(input > x){
        cout << "The random number is smaller than your input" << endl;
        cout << "Please guess again: " << endl;
        return false;
    } else if(input == x){
        cout << "Congratulations, you guessed the right number" << endl;
        cout << "You needed " << trys << " trys to guess the right number." << endl;
        return true;
    } else {
        cout << "An error has occurred, the program will shut down." << endl;
        return true;
    }
}

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

char checkUserInputChar(){
    char input;
    bool correctInput = false;

    do {
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
    } while (!correctInput);
    return input;
}


bool playingAgain() {
    char decision;

    cout << "Do you want to play again? (yes = y; no = n)" << endl;

    while (true) {
        decision = checkUserInputChar();

        if (decision == 'y') {
            return false;
        } else if (decision == 'n') {
            return true;
        } else {
            cout << "This letter was not accepted by the program. Please try again: " << endl;
        }
    }
}
