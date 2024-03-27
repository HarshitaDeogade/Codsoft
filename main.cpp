/* a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1; 
    int guess;
    int tries = 0;

    cout << "Welcome to Guess the Number Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Can you guess what it is?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << tries << " tries!" << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
