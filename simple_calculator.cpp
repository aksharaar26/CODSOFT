#include <iostream>

using namespace std;

int main() {
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        float x, y;
        char operation;
        cout << "Enter first number,x: ";
        cin >> x;

        cout << "Enter second number,y: ";
        cin >> y;

        cout << "Enter the operation (+, -, *, /): ";
        cin >> operation;

        float result;

        switch (operation) {
            case '+':
                result = x + y;
                break;
            case '-':
                result = x - y;
                break;
            case '*':
                result = x * y;
                break;
            case '/':
                result = x / y;
                break;
        }

        cout << "The result of " << x << ' ' << operation << ' ' << y << " is: " << result << 
endl;

    }

    return 0;
}
