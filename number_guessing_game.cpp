#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "Let's Play a Number Riddle!\n";
    
    cout << "Try to guess a random number between 1 and 50.\n";
    
    cout << "Shall we Start?\n";

   
    srand(time(0));
    int randNumber = rand() % 50+ 1;

    int guess;

    for (;;) {
        cout << "Guess a Number: ";
        cin >> guess;

        if (guess == randNumber) {
            cout << "Hurrey! You got the number.\n";
            break;
        } else if (guess > randNumber) {
            cout << "Oops!Try a Smaller one.\n";
        } else {
            cout << "Oops! Try a Larger one.\n";
        }
    }
    return 0;
}
