/*
Name: Matthew Braziel
CS 4350 - Unix Systems Programming
Section Number: 001
Assignment Number: 4
Due Date: 10/05/2026 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generateNumbers(void);
int reproduceSum(int desiredSum);

int main(void)
{
    int choice;
    int desiredSum;
    int attempts;
    char again[10];

    srand(time(NULL));

    printf("Practicing C Programming Language\n");
    printf("This App. generates two random numbers between 2 and 20\n");
    printf("inclusive. A sum will be calculated by adding the two generated\n");
    printf("numbers. Then, the program will find the number of times it\n");
    printf("takes for the sum to be reproduced again. Process is repeated\n");
    printf("until No is entered.\n\n");

    printf("Enter One of The Following:\n");
    printf("1 - Run The Application\n");
    printf("9 - Exit The Program ------ > ");
    scanf("%d", &choice);

    while (choice != 1 && choice != 9)
    {
        printf("Invalid Choice - Enter 1 or 9 ----- > ");
        scanf("%d", &choice);
    }

    if (choice == 9)
    {
        printf("Implemented By Matthew Braziel\n");
        printf("October 5th - 2026\n");
        return 0;
    }

    if (choice == 1)
    {
        do
        {
            desiredSum = generateNumbers();

            printf("Processing . . . . . . .\n");

            attempts = reproduceSum(desiredSum);

            printf("Number of Times the Numbers were Generated\n");
            printf("Before the Desired sum was reached = %d\n", attempts);

            printf("Run The App. Again Yes ? No ----- > ");
            scanf("%9s", again);

            while (strcmp(again, "Yes") != 0 && strcmp(again, "No") != 0)
            {
                printf("Invalid Choice - Enter Yes / No ----- > ");
                scanf("%9s", again);
            }

        } while (strcmp(again, "Yes") == 0);
    }

    printf("Implemented By Matthew Braziel\n");
    printf("October 5th - 2026\n");
    return 0;
}
/*
reproduceSum: Generates two random numbers until their sum matches
desired sum and returns the # of attempts. */

int reproduceSum(int desiredSum)
{
    int firstNumber;
    int secondNumber;
    int sum;
    int count = 0;

    do
    {
        firstNumber = rand() % 19 + 2;
        secondNumber = rand() % 19 + 2;
        sum = firstNumber + secondNumber;

        count++;

        printf("Generating First Number = %d\n", firstNumber);
        printf("Generating Second Number = %d\n", secondNumber);
        printf("The sum of the generated numbers is : %d\n", sum);

    } while (sum != desiredSum);

    return count;
}
/*
generateNumbers: Generates two random numbers between 2 and 20,
displays them, and returns their sum. */
int generateNumbers(void)
{
    int firstNumber;
    int secondNumber;
    int sum;

    firstNumber = rand() % 19 + 2;
    secondNumber = rand() % 19 + 2;

    sum = firstNumber + secondNumber;

    printf("First Generated Number : %d\n", firstNumber);
    printf("Second Generated Number : %d\n", secondNumber);
    printf("First Number + Second Number = %d\n", sum);

    return sum;
}

/* End of Program */