#include <iostream>
#include <cstdlib>

bool checkNumber(int input, int x);

using namespace std;

int main() {
    int x = rand() % 100 + 1; //x is the random number between 1 and 100
    bool end;// variable to end the loop
    int input, trys = 0; //input is for saving the guess of the user. trys for counting the trys the user needed.

    cout << "The number is set, you can write your answer now." << endl;
    do{
        cin >> input;
        end = checkNumber(input, x);
        trys++;
    } while (!end);
    cout << "You needed " << trys << " trys to guess the right number." << endl;
    return 0;
}

/**
 * function to check the number from the user
 * @param input the input from the user
 * @param x the number that has to be guess
 * @return true if correct, false if not correct
 */
bool checkNumber(int input, int x) {
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
        return true;
    } else {
        cout << "An error has occurred, the program will shut down." << endl;
        return true;
    }
}
