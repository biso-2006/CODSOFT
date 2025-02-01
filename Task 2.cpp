#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "Welcome to the Simple Calculator!\n";
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed!" << endl;
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            cout << " Error: Invalid operator! Please use +, -, *, or /." << endl;
            return 1;
    }

    cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << endl;
    cout << "Thanks for using the calculator!\n Do you want to try again? T/F\n";
    string again;
    cin >> again;
    if (again == "T" || again == "t") {
        main();
    } else {
        cout << "Goodbye!\n";
    }
    return 0;
}
