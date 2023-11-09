#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MIN 0
#define RAND_MAX 100

//John Currie
//CIS 2107
//Lab 4
//9/24/2023
//This program will take in a number from the user and create an array of that size
//It will then fill the array with random numbers between 0 and 100
//It will then run an assortment of functions on the array

void fillArray(int myArray[], int size);
int findWithRange(int myArray[], int start, int finish);
void reverseArray(int myArray[], int size);
void reverseSelectedRangeWithinArray(int myArray[], int start, int finish);
int findSequence(int myArray[], int size, int num1, int num2);
void checkRange(int *rangeLow, int *rangeHigh, int size);

int main(void){
    unsigned int size = 0;
    printf("%s","Enter the size of the array: ");
    scanf("%d", &size);
    int myArray[size];
    fillArray(myArray, size);
    for(int i = 0; i < size; i++){
        printf("%d ", myArray[i]);
    }
    puts("\n");
    int rangeLow = 0;
    int rangeHigh = 0;
    printf("Enter two numbers within the range of the array[%d]: ", size);
    scanf("%d%d", &rangeLow, &rangeHigh);
    checkRange(&rangeLow, &rangeHigh, size);

    int max = findWithRange(myArray, rangeLow, rangeHigh);
    printf("This is the max of the array within this range [%d-%d]: %d\n\n", rangeLow, rangeHigh, max);

    puts("Reversing the array:");
    reverseArray(myArray, size);
    for(int i = 0; i < size; i++){
        printf("%d ", myArray[i]);
    }
    puts("\n");

    printf("Enter two numbers within the range of the array[%d]: ", size);
    scanf("%d%d", &rangeLow, &rangeHigh);
    checkRange(&rangeLow, &rangeHigh, size);

    reverseSelectedRangeWithinArray(myArray, rangeLow, rangeHigh);
    puts("reversing in this range:");
    for(int i = 0; i < size; i++){
        printf("%d ", myArray[i]);
    }
    puts("\n");

    int num1 = 0;
    int num2 = 0;
    printf("Enter two digits to see if the sequence is in the array: ");
    scanf("%d%d", &num1, &num2);
    int indexSequence = findSequence(myArray, size, num1, num2);
    printf("The sequence %d %d is in the array at index %d\n", num1, num2, indexSequence);

    return 0;
}

void fillArray(int myArray[], int size){
    srand((unsigned) time(NULL));
    int i = 0;
    for(i; i < size; i++){
        myArray[i] = rand() % (RAND_MAX + 1) + RAND_MIN;
    }
}

int findWithRange(int myArray[], int start, int finish){
    int i = start;
    int max = myArray[i];
    for(i; i < finish; i++){
        if(myArray[i] > max){
            max = myArray[i];
        }
    }
    return max;
}

void reverseArray(int myArray[], int size){
    int i = 0;
    int temp = 0;
    for(i; i < size/2; i++){
        temp = myArray[i];
        myArray[i] = myArray[size-i-1];
        myArray[size-i-1] = temp;
    }
}

void reverseSelectedRangeWithinArray(int myArray[], int start, int finish){
    int i = start;
    int temp = 0;
    for(i; i < finish; i++){
        temp = myArray[i];
        myArray[i] = myArray[finish];
        myArray[finish--] = temp;
    }
}

int findSequence(int myArray[], int size, int num1, int num2){
    int i = 0;
    int index = -1;
    for(i; i < size-1; i++){
        if(myArray[i] == num1 && myArray[i+1] == num2){
            index = i;
            break;
        }
    }
    return index;
}

void checkRange(int *rangeLow, int *rangeHigh, int size){
    //swaps the low and high if low is greater than high
    if(*rangeLow > *rangeHigh){
        int temp = *rangeLow;
        *rangeLow = *rangeHigh;
        *rangeHigh = temp;
    }
    //if the low is less than 0 sets low to 0 so that the program can still run
    if(*rangeLow < 0){
        *rangeLow = 0;
        puts("\nThe low range was below 0, so it was set to 0");
    }
    //if the high is greater than the last index of the array sets the high to the last index
    if(*rangeHigh > size-1){
        *rangeHigh = size-1;
        puts("The high range was above the size of the array, so it was set to the size of the array\n");
    }
}