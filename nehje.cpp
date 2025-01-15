#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

void enterNumbers(int arr[]);
void bubbleSort(int arr[]);
void largestElement(int arr[]);
void primeNumbers(int arr[]);

int main() {
    int choice;
    char continueProgram = 'Y';
    int arr[10];

    do {
        cout << "\n\nData Structures and Algorithms\n       Final Project";
        cout << "\n\n         Main Menu";
        cout << "\n----------------------------------";
        cout << "\n[1] Bubble Sort\n[2] Largest Element in the Array\n[3] Prime Number Identifier\n[4] Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "\n\nData Structures and Algorithms\n       Final Project";
        }

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
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                continue;
        }

        do {
            cout << "\nDo you want to perform another operation? (Y/N): ";
            cin >> continueProgram;

            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continueProgram = '\0';
            }
        } while (strchr("yYnN", continueProgram) == nullptr);

    } while (continueProgram == 'y' || continueProgram == 'Y');

    return 0;
}

void enterNumbers(int arr[]) {
    cout << "\nEnter a set of 10 values: ";
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }
    cout << "\n";
}

void bubbleSort(int arr[]) {
    bool isSorted = false;
    int pass = 0;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < 9 - pass; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = false;
            }
        }
        cout << "Pass " << ++pass << ": ";
        for (int i = 0; i < 10; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

void largestElement(int arr[]) {
    int max = arr[0];
    for (int i = 1; i < 10; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "The largest element in the array is: " << max << "\n";
}

void primeNumbers(int arr[]) {
    cout << "Prime numbers in the array are: ";
    for (int i = 0; i < 10; ++i) {
        if (arr[i] > 1) {
            bool isPrime = true;
            for (int j = 2; j * j <= arr[i]; ++j) {
                if (arr[i] % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                cout << arr[i] << " ";
            }
        }
    }
    cout << "\n";
}
