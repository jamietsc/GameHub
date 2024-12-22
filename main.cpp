#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int x = rand() % 100 + 1; //x ist im Bereich von 1 bis 100
    bool end = false; // Variable um die Schleife zu beenden
    int input, trys; //Variable um die Eingabe des Nutzer zu speichern

    cout << "The number is set, you can write your answer now." << endl;
    do{
        cin >> input;
        if(input < x){
            cout << "The random number is bigger than your input." << endl;
            cout << "Please guess again: " << endl;
        } else if(input > x){
            cout << "The random number is smaller than your input" << endl;
            cout << "Please guess again: " << endl;
        } else if(input == x){
            cout << "Congratulations, you guessed the right number" << endl;
            end = true;
        } else {
            cout << "An error has occurred, the program will shut down." << endl;
            return 1;
        }
    } while (!end);
    return 0;
}
