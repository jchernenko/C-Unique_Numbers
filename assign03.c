// Created by: Jeff Chenenko - A00745858
// COMP 2511 - Procedural Programming with C

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

// function prototype
bool isUnique(int num, int array[]);

// driver
int main() {

    int arr[SIZE];

    // initializing the array
    for (int j = 0; j < SIZE; ++j) {
        arr[j] = -1;
    }

    int i = 0;
    int input; // variable used to store user input
    bool isUniqueNum; // variable used to hold boolean is input is unique or not

    while (i < SIZE) {

        printf("Enter # %d: ", i + 1);
        scanf("%d", &input); // read input

        // checks if input is between 10 - 100
        if (input >= 10 && input <= 100) {

            // return true or false bool based on input
            isUniqueNum = isUnique(input, arr); 

            if (isUniqueNum) { // if input is true
                printf("The number: %d is unique\n", input);
                arr[i] = input; // add unique num to the array
            }

            puts("");
            ++i; //increments i whether input unique or not, as long as input within range
        }
        else { // if input is out of range
            printf("The number entered is not in the valid range of 10 to 100\n\n");
        }
    } // end while loop

    printf("\nAll of the unique numbers found are:\n\n");

    int count = 0;

    for (int i = 0; i < SIZE; i++) {

        if (arr[i] != -1) {
            printf(" %5d", arr[i]); // prints array in table format 5 wide
            count++;

            if (count % 5 == 0) {
                printf("\n"); // new line after every 5 numbers
            }
        }
    } // end for loop

    puts("");
    return 0;

} // end main()


/*
isUnique() returns true or false based on
if integer is already stored in the array
*/
bool isUnique(int num, int array[]) {

    for (int i = 0; i < SIZE; i++) {

        if (array[i] == num) { // checks if number is already in array
            return false; // if it is, number is not unique
        }
    }

    return true; // if it is not, number is unique

} // end isUnique()
