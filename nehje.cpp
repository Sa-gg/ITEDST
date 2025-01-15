#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

void enterNumbers(vector<int>& arr);
void bubbleSort(vector<int>& arr);
void largestElement(const vector<int>& arr);
void primeNumbers(const vector<int>& arr);
void clearScreen();
int getValidInput();
bool continueProgram();
void exitProgram();
bool checkInput(vector<int>& arr);

int main() {
    vector<int> arr(10);

    while (true) {
        clearScreen();
        cout << "\n\nData Structures and Algorithms\n       Final Project";
        cout << "\n\n         Main Menu";
        cout << "\n----------------------------------";
        cout << "\n[1] Bubble Sort\n[2] Largest Element in the Array\n[3] Prime Number Identifier\n[4] Exit\n\n";
        cout << "Enter your choice: ";
        int choice = getValidInput();

        if (choice == 4) {
            exitProgram();
            continue;
        }

        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        while (true) {
            clearScreen();
            cout << "\n\nData Structures and Algorithms\n       Final Project";

            switch (choice) {
                case 1:
                    cout << "\n\n        Bubble Sort";
                    cout << "\n----------------------------------";
                    cout << "\nThis mini program will sort a set of 10 numbers using the Bubble Sort algorithm.\n";
                    enterNumbers(arr);
                    bubbleSort(arr);
                    break;
                case 2:
                    cout << "\n\n Largest Element in the Array";
                    cout << "\n----------------------------------";
                    cout << "\nThis mini program will find the largest element in a set of 10 numbers.\n";
                    enterNumbers(arr);
                    largestElement(arr);
                    break;
                case 3:
                    cout << "\n\n   Prime Number Identifier";
                    cout << "\n----------------------------------";
                    cout << "\nThis mini program will find all prime numbers in a set of 10 numbers.\n";
                    enterNumbers(arr);
                    primeNumbers(arr);
                    break;
            }

            if (!continueProgram()) {
                break;
            }
        }
    }

    return 0;
}

int getValidInput() {
    int input;
    while (true) {
        if (!(cin >> input) || cin.peek() != '\n') {
            cout << "\033[1;31mInvalid input. Please enter a valid number.\033[0m\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter your choice: ";
        } else {
            if (input >= 1 && input <= 4) {
                return input;
            } else {
                cout << "\033[1;31mInvalid choice. Please enter a number between 1 and 4.\033[0m\n";
                cout << "Enter your choice: ";
            }
        }
    }
}

void exitProgram() {
    char continueChoice;
    do {
        cout << "\nAre you sure you want to EXIT [Y/N]: ";
        cin >> continueChoice;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "\033[1;31mInvalid input. Please enter a single character: 'Y' or 'N'.\033[0m\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (strchr("yYnN", continueChoice) == nullptr) {
            cout << "\033[1;31mInvalid input. Please enter 'Y' or 'N'.\033[0m\n";
        } else if (continueChoice == 'Y' || continueChoice == 'y') {

        } else {
            clearScreen();
            return;
        }
    } while (true);
}

bool continueProgram() {
    char continueChoice;
    while (true) {
        cout << "\nDo you want to continue [Y/N]: ";
        cin >> continueChoice;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "\033[1;31mInvalid input. Please enter a single character: 'Y' or 'N'.\033[0m\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (strchr("yYnN", continueChoice)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return (continueChoice == 'Y' || continueChoice == 'y');
        } else {
            cout << "\033[1;31mInvalid input. Please enter 'Y' or 'N'.\033[0m\n";
        }
    }
}

bool checkInput(vector<int>& arr) {
    int ch;
    for (int i = 0; i < 10; i++) {
        if (!(cin >> arr[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
    }
    if ((ch = getchar()) != '\n' && ch != EOF) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void enterNumbers(vector<int>& arr) {
    while (true) {
        cout << "\nEnter a set of 10 values: ";
        if (checkInput(arr)) {
            break;
        }
        cout << "\033[1;31mInvalid input. Please enter exactly 10 integers separated by spaces\033[0m\n";
    }
    cout << "\n";
}

void bubbleSort(vector<int>& arr) {
    bool isSorted = false;
    int pass = 0;
    while (!isSorted) {
        isSorted = true;
        for (size_t i = 0; i < arr.size() - 1 - pass; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
        cout << "Pass " << ++pass << ": ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

void largestElement(const vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    cout << "The largest element in the array is: " << max << "\n";
}

void primeNumbers(const vector<int>& arr) {
    cout << "Prime numbers in the array are: ";
    for (int num : arr) {
        if (num > 1) {
            bool isPrime = true;
            for (int j = 2; j * j <= num; ++j) {
                if (num % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                cout << num << " ";
            }
        }
    }
    cout << "\n";
}

void clearScreen() {
    system("cls");
}
