#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {    
    int menuChoice, arr[10];
    while(true) {
        printf("\n\nData Structures and Algorithms\n       Final Project \n\n         Main Menu\n----------------------------------\n[1] Bubble Sort\n[2] Largest Element in the Array\n[3] Prime Number Identifier\n[4] Exit\n\n");
        printf("Enter your choice: ");
        if (scanf("%d", &menuChoice) != 1) {
            printf("\033[1;31mInvalid input. Please enter a valid number.\033[0m\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (menuChoice) {
            case 1:
                while (true) {
                    system("cls");
                    printf("\nData Structures and Algorithms\n       Final Project \n\n        Bubble Sort\n----------------------------------\nThis mini program will sort a set of 10 numbers using the Bubble Sort algorithm.\n");
                    enterNumber(arr);  bubbleSort(arr);
                    if (continueProgram() == 1) { continue; } else { break;}
                }
                break;
            case 2:
            while (true) {
                    system("cls");
                    printf("\nData Structures and Algorithms\n       Final Project \n\n Largest Element in the Array\n----------------------------------\nThis mini program will find the largest element in a set of 10 numbers.\n");
                    enterNumber(arr);  largestElement(arr);
                    if (continueProgram() == 1) { continue; } else { break;}
                }
                break;
            case 3:
            while (true) {
                    system("cls");
                    printf("\nData Structures and Algorithms\n       Final Project \n\n   Prime Number Identifier\n----------------------------------\nThis mini program will find all prime numbers in a set of 10 numbers.\n");
                    enterNumber(arr);  primeNumber(arr);
                    if (continueProgram() == 1) { continue; } else { break;}
                }
                break;
            case 4:
                exitProgram();
                break; 
            default:
                printf("\033[1;31mInvalid input. Please enter a valid number.\033[0m\n");
                break;
        }   
    } 
}

void exitProgram() {
    char continueChoice;
    do {
        printf("\nAre you sure you want to EXIT [Y/N]: ");
        scanf(" %c", &continueChoice);
        while (getchar() != '\n'); 
        if (strchr("yYnN", continueChoice) == NULL) {
            printf("\033[1;31mInvalid input. Please enter 'Y' or 'N'.\033[0m\n");
        } else if (continueChoice == 'Y' || continueChoice == 'y') {
            exit(0); 
        } else {
            system("cls");
            return; 
        }
    } while (1);
}

int continueProgram() {
    char continueChoice;
    do {
        printf("\nDo you want to continue [Y/N]: ");
        scanf(" %c", &continueChoice);
        while (getchar() != '\n'); 
        if (strchr("yYnN", continueChoice) == NULL) {
            printf("\033[1;31mInvalid input. Please enter 'Y' or 'N'.\033[0m\n");
        } else if (continueChoice == 'Y' || continueChoice == 'y') {
            system("cls");
            return 1; 
        } else {
            system("cls");
            return 2; 
        }
    } while (1);
}

void enterNumber(int arr[]) {
    printf("\nEnter a set of 10 values: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[]) {
    bool isSorted = false;
    int pass = 0;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < 9 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = false;   
            }
        }
        printf("Pass %d: ", ++pass);
        for (int k = 0; k < 10; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void largestElement(int arr[]) {
    int max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The largest element in the array is: %d\n", max);
}

void primeNumber(int arr[]) {
    printf("Prime numbers in the array are: ");
    for (int i = 0; i < 10; i++) {
        int isPrime = arr[i] > 1;
        for (int j = 2; j * j <= arr[i] && isPrime; j++) {
            if (arr[i] % j == 0) isPrime = 0;
        }
        if (isPrime) printf("%d ", arr[i]);
    }
    printf("\n");
}




