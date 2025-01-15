import java.util.Scanner;

public class FinalProject {
    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        Scanner scanner = new Scanner(System.in);
        int[] arr = new int[10];
        while (true) {
            System.out.println("\n\n     Data Structures and Algorithms \n             Final Project          ");
            System.out.println("\n\n+=====================================+");
            System.out.println("|              Main Menu              |");
            System.out.println("+=====================================+");
            System.out.println("| [1] - Bubble Sort                   |\n| [2] - Largest Element in the Array  |\n| [3] - Prime Number Identifier       |\n| [4] - Exit                          |");
            System.out.println("+=====================================+");
            System.out.print("Enter your choice: ");
            int menuChoice = getValidInput(scanner, 1, 4);
            switch (menuChoice) {
                case 1:
                    while (true) {
                        clearConsole();
                        System.out.println("\n\n                           Data Structures and Algorithms \n                                   Final Project          ");
                        System.out.println("\n\n+==================================================================================+");
                        System.out.println("|                                   BUBBLE SORT                                    |");
                        System.out.println("+==================================================================================+");
                        System.out.println("| This mini program will sort a set of 10 numbers using the Bubble Sort algorithm. |");
                        System.out.println("+==================================================================================+");
                        enterNumbers(scanner, arr);                   
                        bubbleSort(arr);
                        if (!continueProgram(scanner)) break;
                    }
                    break;
                case 2:
                    while (true) {
                        clearConsole();
                        System.out.println("\n\n                           Data Structures and Algorithms \n                                   Final Project          ");
                        System.out.println("\n\n+===================================================================================+");
                        System.out.println("|                           LARGEST ELEMENT IN THE ARRAY                            |");
                        System.out.println("+===================================================================================+");
                        System.out.println("|      This mini program will find the largest element in a set of 10 numbers.      |");
                        System.out.println("+===================================================================================+");
                        enterNumbers(scanner, arr);
                        largestElement(arr);
                        if (!continueProgram(scanner)) break;
                    }
                    break;
                case 3:
                    while (true) {
                        clearConsole();
                        System.out.println("\n\n                             Data Structures and Algorithms \n                                    Final Project          ");
                        System.out.println("\n\n+===================================================================================+");
                        System.out.println("|                              PRIME NUMBER IDENTIFIER                              |");
                        System.out.println("+===================================================================================+");
                        System.out.println("|       This mini program will find all prime numbers in a set of 10 numbers.       |");
                        System.out.println("+===================================================================================+");
                        enterNumbers(scanner, arr);
                        primeNumbers(arr);
                        if (!continueProgram(scanner)) break;
                    }
                    break;
                case 4:
                    long endTime = System.currentTimeMillis();
                    double totalExecutionTimeInSeconds = (startTime - endTime) / 1000.0; // Convert ms to seconds
                    System.out.printf("Total execution time: %.2f seconds%n", totalExecutionTimeInSeconds);
                    exitProgram(scanner);
                    break;
            }
        }
    }

    public static int getValidInput(Scanner scanner, int min, int max) {
        while (true) {
            try {
                int input = Integer.parseInt(scanner.nextLine());
                if (input >= min && input <= max) {
                    return input;
                } else {
                    System.err.println("Invalid choice. Please enter a number between " + min + " and " + max + ".");
                }
            } catch (NumberFormatException e) {
                System.err.println("Invalid input. Please enter a valid number.");
            }
        }
    }

    public static void exitProgram(Scanner scanner) {
        while (true) {
            System.out.print("\nAre you sure you want to EXIT [Y/N]: ");
            String choice = scanner.nextLine().trim().toUpperCase();
            if (choice.equals("Y")) {
                System.exit(0);
            } else if (choice.equals("N")) {
                clearConsole();
                return;
            } else {
                System.err.println("Invalid input. Please enter 'Y' or 'N'.\n");
            }
        }
    }

    public static boolean continueProgram(Scanner scanner) {
        while (true) {
            System.out.print("\nDo you want to continue [Y/N]: ");
            String choice = scanner.nextLine().trim().toUpperCase();
            if (choice.equals("Y")) {
                clearConsole();
                return true;
            } else if (choice.equals("N")) {
                clearConsole();
                return false;
            } else {
                System.err.println("Invalid input. Please enter 'Y' or 'N'.\n");
            }
        }
    }

    public static void enterNumbers(Scanner scanner, int[] arr) {
        System.out.print("\nEnter a set of 10 values (space-separated): ");
        while (true) {
            try {
                String[] inputs = scanner.nextLine().trim().split("\\s+");
                if (inputs.length != 10) throw new NumberFormatException();
                for (int i = 0; i < 10; i++) {
                    arr[i] = Integer.parseInt(inputs[i]);
                }
                break;
            } catch (NumberFormatException e) {
                System.err.println("Invalid input. Please enter exactly 10 integers separated by spaces.");
            }
        }
    }

    public static void bubbleSort(int[] arr) {
        boolean isSorted;
        int pass = 0;
        do {
            isSorted = true;
            for (int i = 0; i < arr.length - 1 - pass; i++) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    isSorted = false;
                }
            }
            pass++;
            System.out.print("Pass " + pass + ": ");
            for (int num : arr) {
                System.out.print(num + " ");
            }
            System.out.println();
        } while (!isSorted);
    }

    public static void largestElement(int[] arr) {
        int max = arr[0];
        for (int num : arr) {
            if (num > max) {
                max = num;
            }
        }
        System.out.println("The largest element in the array is: " + max);
    }

    public static void primeNumbers(int[] arr) {
        System.out.print("Prime numbers in the array are: ");
        for (int num : arr) {
            if (isPrime(num)) {
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }

    public static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static void clearConsole() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}
