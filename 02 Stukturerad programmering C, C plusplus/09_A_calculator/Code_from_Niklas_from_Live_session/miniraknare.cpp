// miniraknare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

double addition(double number1, double number2) {
    double result = number1 + number2;
    return result;
}

double subtraction(double number1, double number2) {
    double result = number1 - number2;
    return result;
}

double multiplication(double number1, double number2) {
    double result = number1 * number2;
    return result;
}

double division(double number1, double number2) {
    double result = number1 / number2;
    return result;
}

double getNumberFromString(string numberString, double result) {
    double number;
    if (numberString == "Last") {
        number = result;
    }
    else if (numberString == "one") {
        number = 1;
    }
    else {
        number = stod(numberString);
    }

    return number;
}


int main()
{
    cout << "Hello World!\n";

    bool ongoing = true;

    while (ongoing == true) {

        string number1string;
        string number2string;
        double number1;
        double number2;
        double result = 0;

        int numberArray[40] = {};
        string commandArray[40] = {};

        string desiredNumbersString;
        double desiredNumbers = 0;

        cout << "Input amount of numbers\n";

        cin >> desiredNumbersString;
        if (desiredNumbersString == "Stop") {
            ongoing = false;
            break;
        }
        else {
            desiredNumbers = getNumberFromString(desiredNumbersString, result);
        }

        for (int i = 0; i < desiredNumbers; i++) {
            if (i != 0) {
                cout << "Insert operator.\n";
                cin >> commandArray[i - 1];
            }

            cout << "Insert number.\n";
            string numberString;
            cin >> numberString;
            if (numberString == "Stop") {
                ongoing = false;
                break;
            }
            else {
                numberArray[i] = getNumberFromString(numberString, result);
            }
        }

        result = numberArray[0];

        cout << result;
        for (int i = 1; i < desiredNumbers; i++) {
            double number = numberArray[i];
            string commandString = commandArray[i-1];

            if (commandString == "+" || commandString == "add") {
                result = addition(result, number);
                cout << " + " << number;
            }
            else if (commandString == "-" || commandString == "subtract") {
                result = subtraction(result, number);
                cout << " - " << number;
            }
            else if (commandString == "*") {
                result = multiplication(result, number);
                cout << " * " << number;
            }
            else if (commandString == "/") {
                result = division(result, number);
                cout << " / " << number;
            }
        }

        cout << " = " << result << "\n";

        /*
        cout << "Input two numbers.\n";

        cin >> number1string;
        if (number1string == "Stop") {
            ongoing = false;
            break;
        }
        else {
            number1 = getNumberFromString(number1string, result);
        }

        cin >> number2string;
        if (number2string == "Stop") {
            ongoing = false;
            break;
        }
        else {
            number2 = getNumberFromString(number2string, result);
        }

        string commandString;

        cout << "Input desired command:\n";
        cin >> commandString;

        //char acceptableVariable = '+';

        /*switch (commandString) {
            case "+":
                result = addition(number1, number2);
                cout << number1 << " + " << number2;
                break;
            case "-":

                break;
        }*/

        /*if (commandString == "+" || commandString == "add") {
            result = addition(number1, number2);
            cout << number1 << " + " << number2;
        }
        else if (commandString == "-" || commandString == "subtract") {
            result = subtraction(number1, number2);
            cout << number1 << " - " << number2;
        }
        else if (commandString == "*") {
            result = multiplication(number1, number2);
            cout << number1 << " * " << number2;
        }
        else if (commandString == "/") {
            result = division(number1, number2);
            cout << number1 << " / " << number2;
        }

        cout << " = " << result << "\n\n";*/
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
