#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int numRow, int numColumn, int myArray[numRow][numColumn]);
int rowSum(int targetRow, int numRow, int numColumn, int myArray[numRow][numColumn]);
int columnSum(int targetColumn, int numRow, int numColumn, int myArray[numRow][numColumn]);
bool isSquare(int numRow, int numColumn);
void displayOutputs(int numRow, int numColumn, int myArray[numRow][numColumn]);

int main(void){
    int numRow = 0;
    int numColumn = 0;
    printf("%s", "How any rows? ");
    scanf("%d", &numRow);
    printf("%s", "How many columns? ");
    scanf("%d", &numColumn);

    int myArray[numRow][numColumn];
    for(int i = 0; i < numRow; i++){
        for(int j = 0; j < numColumn; j++){
            printf("enter [%d][%d]: ", i, j);
            scanf("%d", &myArray[i][j]);
        }
    }

    printf("\nMax = %d\n\n", max(numRow, numColumn, myArray));

    for(int i = 1; i <= numRow; i++){
        printf("Sum of row %d = %d\n", i, rowSum(i-1, numRow, numColumn, myArray));
    }
    puts("");

    for(int i = 1; i <= numColumn; i++){
        printf("Sum of column %d = %d\n", i, columnSum(i-1, numRow, numColumn, myArray));
    }
    puts("");

    if(isSquare(numRow, numColumn)){
        printf("%s", "This is a square array\n\n");
    }else{
        printf("%s", "This is not a square array\n\n");
    }

    displayOutputs(numRow, numColumn, myArray);
    return 0;
}

int max(int numRow, int numColumn, int myArray[numRow][numColumn]){
    int max = myArray[0][0];
    for(int i = 0; i < numRow; i++){
        for(int j = 0; j < numColumn; j++){
            if(myArray[i][j] > max){
                max = myArray[i][j];
            }
        }
    }
    return max;
}

int rowSum(int targetRow, int numRow, int numColumn, int myArray[numRow][numColumn]){
    int sum = 0;
    for(int i = 0; i < numColumn; i++){
        sum += myArray[targetRow][i];
    }
    return sum;
}

int columnSum(int targetColumn, int numRow, int numColumn, int myArray[numRow][numColumn]){
    int sum = 0;
    for(int i = 0; i < numRow; i++){
        sum += myArray[i][targetColumn];
    }
    return sum;
}

bool isSquare(int numRow, int numColumn){
    return numRow == numColumn;
}

void displayOutputs(int numRow, int  numColumn, int myArray[numRow][numColumn]){
    for(int i = 0; i < numRow; i++){
        printf("%s", "[");
        for(int j = 0; j < numColumn; j++){
            if(j != numColumn-1){
            printf("%d, ", myArray[i][j]);
            }else{
                printf("%d", myArray[i][j]);
            }
        }
        printf("%s", "]\n");
    }
}




