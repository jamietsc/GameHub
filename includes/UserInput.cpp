//
// Created by sauser on 24.12.2024.
//
#include <iostream>
#include <limits>

using namespace std;

int checkUserInputInteger();
char checkUserInputChar();

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