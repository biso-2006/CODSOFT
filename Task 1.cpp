#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int MAX = 100;
    srand(time(0)); // for rand to work
    int secretNumber = rand() % MAX + 1; // can change the MAX value to change the range
    int guess;
    int attempts = 0; // added to make the game more interesting
    try // for exception handling if dev tries to
    {
        if (secretNumber < 1 || secretNumber > MAX)
        {
            throw "The secret number is out of range!";
        }
    }
    catch (const char* msg)
    {
        cerr << msg << endl;
        return 1;
    }
    cout << " Welcome to the Number Guessing Game!\n";
    cout << "I've picked a number between 1 and "<< MAX << ". Can you guess it?\n";

    do {
        Retry:
        cout << "Enter your guess: ";
        cin >> guess;
        try // for exception handling a number greater than max or less than 1
        {
            if (guess < 1 || guess > MAX)
            {
                throw "The number you entered is out of range! Please try again!, this will not count as an attempt!\n";
            }
        }
        catch (const char* msg)
        {
            cerr << msg << endl;
            goto Retry;
        }
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Please try again!\n"; // feedback for the user
        } else if (guess < secretNumber) {
            cout << "Too low! Please try again!\n";  // feedback for the user
        } else {
            cout << " Congrats! You got it in " << attempts << " attempts!\n";
        }
    } while (guess != secretNumber);

    cout << "This is the end of the game! Thanks for playing! \n";
    return 0;
}
